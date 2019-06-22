#include "MKL46Z4.h"
#include "clock.h"


/* clock enable */
void clock_enable()
{
	/* PortC clock enable */
	SIM->SCGC5 |= SIM_SCGC5_PORTC(1);  
	/* PortE clock enable */
	SIM->SCGC5 |= SIM_SCGC5_PORTE(1);
}

/* 8Mhz */
void UpdateClockTo8Mhz()
{
    MCG->C1 &= ~MCG_C1_CLKS_MASK;
    MCG->C1 |= MCG_C1_IREFS_MASK;
    MCG->C6 &= ~MCG_C6_PLLS_MASK;
  
    MCG->C4 &= ~MCG_C4_DRST_DRS_MASK;
    MCG->C4 |= MCG_C4_DMX32_MASK;
    
    SIM->CLKDIV1 &= ~SIM_CLKDIV1_OUTDIV1_MASK;
    SIM->CLKDIV1 |= SIM_CLKDIV1_OUTDIV1(2);   
}

/* Config PEI to PEE 48Mhz */
void ConfigFEIToPEE48Mhz()
{
    /* C2[RANGE0] set to 01 */
    MCG->C2 &= ~MCG_C2_RANGE0_MASK;
    MCG->C2 |= MCG_C2_RANGE0(1);
    /* C2[HGO0] set to 1 */
    MCG->C2 |= MCG_C2_HGO0_MASK;
    /* C2[EREFS0] set to 1 */
    MCG->C2 |= MCG_C2_EREFS0_MASK;
    
    /* C1[CLKS] set to 10 */
    MCG->C1 &= ~MCG_C1_CLKS_MASK;
    MCG->C1 |= MCG_C1_CLKS(2);
    /* C1[FRDIV] set to 011 */
    MCG->C1 &= ~MCG_C1_FRDIV_MASK;
    MCG->C1 |= MCG_C1_FRDIV(3);
    /* C1[IREFS] cleared to 0 */
    MCG->C1 &= ~MCG_C1_IREFS_MASK;
    
    /* Loop until S[OSCINIT0] is 1 */
    while(!(MCG->S & MCG_S_OSCINIT0_MASK));
    
    /* Loop until S[IREFST] is 0 */
    while(MCG->S & MCG_S_IREFST_MASK);
    
    /* Loop until S[CLKST] is 2'b10 */
    while((MCG->S & MCG_S_CLKST_MASK) !=  MCG_S_CLKST(2));
    
    /* Then configure C5[PRDIV0] */
    MCG->C5 &= ~MCG_C5_PRDIV0_MASK;
    MCG->C5 |= MCG_C5_PRDIV0(3); 
    
    /* C6[PLLS] set to 1 */
    MCG->C6 |= MCG_C6_PLLS_MASK;
    MCG->C6 &= ~MCG_C6_VDIV0_MASK;
 
    /* PBE: Loop until S[PLLST] is set */
    while(!(MCG->S & MCG_S_PLLST_MASK));
    
    /* Then loop until S[LOCK0] is set */
    while(!(MCG->S & MCG_S_LOCK0_MASK));
    
    /* C1[CLKS] set to 2'b00 */ 
    MCG->C1 &= ~MCG_C1_CLKS_MASK;;
    
    /* Loop until S[CLKST] are 2'b11 */
    while((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(3));
}
