SHELL= cmd

SRCS=$(wildcard *.c)
OBJ=$(SRCS:%.c=%.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:%.s=%.o)


CC= arm-none-eabi-
CFLAGS= -gdwarf-2 -mcpu=arm926ej-s
INCS = -I .

TARGET = application

all:${TARGET}.bin
	@echo ========== Build is Done =============
	
$(TARGET).bin: $(TARGET).elf
	$(CC)objcopy.exe -O binary $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld  $(OBJ) -o $(TARGET).elf -Map=Mapfile.map


%.o : %.c 
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
clean : 
	rm -rf*.map  ${TARGET}.*

clean_all : 
	rm -rf *.o *.map  ${TARGET}.*


