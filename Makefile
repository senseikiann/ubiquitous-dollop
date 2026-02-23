CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-mcpu=cortex-m3 -mthumb -O2

all:
	$(CC) $(CFLAGS) main.c -nostdlib -o firmware.elf
	$(OBJCOPY) -O binary firmware.elf firmware.bin
