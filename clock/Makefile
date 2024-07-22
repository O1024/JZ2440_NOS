include $(JZ2440_ROOT_PATH)/Makefile.build

OBJS = crt0.o init.o main.o

all: $(OBJS)
	$(Q)$(CC) $(LDFLAGS) -Ttext 0x0 $(OBJS) -o $(OUTPUT).elf
	$(Q)$(OBJCOPY) -O binary -S $(OUTPUT).elf $(OUTPUT).bin
	$(Q)$(OBJDUMP) -D -m arm $(OUTPUT).elf > $(OUTPUT).dump
	$(Q)echo "\e[32m>>> compiled $(OUTPUT) success.\e[0m"

clean:
	rm -f *.o *.bin *.elf *.dump *.map
