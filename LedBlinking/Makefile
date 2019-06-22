PRO_DIR 	:= .
PROJ_NAME 	:= frdm_kl46z_led_blinking
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR 	:= $(PRO_DIR)/inc
SRC_DIR 	:= $(PRO_DIR)/src
LINKER_FILE := $(PRO_DIR)/linker/MKL46Z256xxx4_flash.ld

COMPLIER_DIR		:= C:/tools/gcc_7_2017-q4-major
PREFIX_GCC_COMPLIER := arm-none-eabi
CC				:= $(COMPLIER_DIR)/bin/$(PREFIX_GCC_COMPLIER)-gcc
ASM				:= $(COMPLIER_DIR)/bin/$(PREFIX_GCC_COMPLIER)-as
LD				:= $(COMPLIER_DIR)/bin/$(PREFIX_GCC_COMPLIER)-ld

FILE_TO_LINK 	:= $(OUTPUT_PATH)/main.o \
				   $(OUTPUT_PATH)/startup_ARMCM0plus.o \
				   $(OUTPUT_PATH)/interrupt.o \
				   $(OUTPUT_PATH)/clock.o \
				   $(OUTPUT_PATH)/gpio.o \
				   $(OUTPUT_PATH)/systick.o \

CC_OPT	:= -march=armv6-m -mcpu=cortex-m0 -c -O0 -g -mthumb -I $(INC_DIR)
ASM_OPT	:= -march=armv6-m -mcpu=cortex-m0 -c -mthumb
LD_OPT	:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

all: clean build

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CC_OPT)	$(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o
	
$(OUTPUT_PATH)/startup_ARMCM0plus.o: $(SRC_DIR)/startup_ARMCM0plus.S
	$(ASM) $(ASM_OPT) $(SRC_DIR)/startup_ARMCM0plus.S -o $(OUTPUT_PATH)/startup_ARMCM0plus.o
	
$(OUTPUT_PATH)/interrupt.o: $(SRC_DIR)/interrupt.c
	$(CC) $(CC_OPT)	$(SRC_DIR)/interrupt.c -o $(OUTPUT_PATH)/interrupt.o
	
$(OUTPUT_PATH)/clock.o: $(SRC_DIR)/clock.c
	$(CC) $(CC_OPT)	$(SRC_DIR)/clock.c -o $(OUTPUT_PATH)/clock.o

$(OUTPUT_PATH)/gpio.o: $(SRC_DIR)/gpio.c
	$(CC) $(CC_OPT)	$(SRC_DIR)/gpio.c -o $(OUTPUT_PATH)/gpio.o

$(OUTPUT_PATH)/systick.o: $(SRC_DIR)/systick.c
	$(CC) $(CC_OPT)	$(SRC_DIR)/systick.c -o $(OUTPUT_PATH)/systick.o


build: $(FILE_TO_LINK) $(LINKER_FILE)
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	
clean:
	@rm -rf $(OUTPUT_PATH)/*