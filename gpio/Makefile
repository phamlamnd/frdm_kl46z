PRO_DIR 	:= .
PROJ_NAME 	:= frdm_kl46z
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR 	:= $(PRO_DIR)/inc
SRC_DIR 	:= $(PRO_DIR)/src
LINKER_FILE := $(PRO_DIR)/linker/MKL46Z256xxx4_flash.ld

COMPLIER_DIR		:= C:/tools/gcc_7_2017-q4-major
PREFIX_GCC_COMPLIER := arm-none-eabi
CC				:= $(COMPLIER_DIR)/bin/$(PREFIX_GCC_COMPLIER)-gcc
ASM				:= $(COMPLIER_DIR)/bin/$(PREFIX_GCC_COMPLIER)-as
LD				:= $(COMPLIER_DIR)/bin/$(PREFIX_GCC_COMPLIER)-ld

FILE_TO_LINK 	:= $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_ARMCM0plus.o

CC_OPT	:= -march=armv6-m -mcpu=cortex-m0 -c -O0 -g -mthumb -I$(INC_DIR)
ASM_OPT	:= -march=armv6-m -mcpu=cortex-m0 -c -mthumb
LD_OPT	:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
#@echo "compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT)	$(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o
	
$(OUTPUT_PATH)/startup_ARMCM0plus.o: $(SRC_DIR)/startup_ARMCM0plus.S
#@echo "compile $(SRC_DIR)/startup_ARMCM0plus.S file"
	$(ASM) $(ASM_OPT) $(SRC_DIR)/startup_ARMCM0plus.S -o $(OUTPUT_PATH)/startup_ARMCM0plus.o

build: $(FILE_TO_LINK) $(LINKER_FILE)
#@echo "link object files to create new binary image $(PROJ_NAME).elf"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	
clean:
#@echo "delete $(SRC_DIR) file"
	@rm -rf $(OUTPUT_PATH)/*