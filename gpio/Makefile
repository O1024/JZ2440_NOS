include $(JZ2440_ROOT_PATH)/Makefile.build

all: $(OBJS)
	$(Q)$(LD) $(LDFLAGS) crt0.o init.o main.o  -o $(OUTPUT).elf
	$(Q)$(OBJCOPY) -O binary -S $(OUTPUT).elf $(OUTPUT).bin
	$(Q)$(OBJDUMP) -D -m arm $(OUTPUT).elf > $(OUTPUT).dis
	$(Q)echo "\e[32m>>> compiled $(OUTPUT) success.\e[0m"

clean:
	rm -f *.o *.bin *.elf *.dis
