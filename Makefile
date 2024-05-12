CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -Os -DF_CPU=42000000L

TARGET = main
SRC = main.c

all:
	$(CC) $(CFLAGS) -o $(TARGET).elf $(SRC)
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
	bossac -d --port=/dev/ttyACM0 -e -w -v $(TARGET).hex -R

clean:
	rm -f $(TARGET).elf $(TARGET).hex