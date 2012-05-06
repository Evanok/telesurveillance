CC=avr-g++
CPP=avr-g++
PWD=$(shell pwd)
ARDUINO_DIR=/home/arthur/robot/arduino-1.0/hardware/arduino/cores/arduino/
VARIANTS=$(ARDUINO_DIR)/../../variants/standard
CCFLAGS=-g -Os -Wall -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=100
CPPFLAGS=-g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=100
ELF_FLAGS=-Os -Wl,--gc-sections -mmcu=atmega328p

romeo: core motor.o sensor.o romeo.o
	@echo "build romeo sources...";
	avr-ar rcs core.a CDC.o
	avr-ar rcs core.a HardwareSerial.o
	avr-ar rcs core.a HID.o
	avr-ar rcs core.a IPAddress.o
	avr-ar rcs core.a new.o
	avr-ar rcs core.a Print.o
	avr-ar rcs core.a Stream.o
	avr-ar rcs core.a Tone.o
	avr-ar rcs core.a USBCore.o
	avr-ar rcs core.a WMath.o
	avr-ar rcs core.a WString.o
	avr-ar rcs core.a main.o
	avr-ar rcs core.a WInterrupts.o
	avr-ar rcs core.a wiring_analog.o
	avr-ar rcs core.a wiring.o
	avr-ar rcs core.a wiring_digital.o
	avr-ar rcs core.a wiring_pulse.o
	avr-ar rcs core.a wiring_shift.o

	$(CC) $(ELF_FLAGS) -o romeo.elf romeo.o motor.o sensor.o core.a -L . -lm

	@echo " done.";

.c.o:
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o $@ $< $(CFLAGS)

core:
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o CDC.o $(ARDUINO_DIR)/CDC.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o HardwareSerial.o $(ARDUINO_DIR)/HardwareSerial.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o HID.o $(ARDUINO_DIR)/HID.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o IPAddress.o $(ARDUINO_DIR)/IPAddress.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o new.o $(ARDUINO_DIR)/new.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o Print.o $(ARDUINO_DIR)/Print.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o Stream.o $(ARDUINO_DIR)/Stream.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o Tone.o $(ARDUINO_DIR)/Tone.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o USBCore.o $(ARDUINO_DIR)/USBCore.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o WMath.o $(ARDUINO_DIR)/WMath.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o WString.o $(ARDUINO_DIR)/WString.cpp $(CFLAGS)
	$(CPP) -c $(CPPFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o main.o $(ARDUINO_DIR)/main.cpp $(CFLAGS)
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o WInterrupts.o $(ARDUINO_DIR)/WInterrupts.c $(CFLAGS)
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o wiring_analog.o $(ARDUINO_DIR)/wiring_analog.c $(CFLAGS)
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o wiring.o $(ARDUINO_DIR)/wiring.c $(CFLAGS)
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o wiring_digital.o $(ARDUINO_DIR)/wiring_digital.c $(CFLAGS)
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o wiring_pulse.o $(ARDUINO_DIR)/wiring_pulse.c $(CFLAGS)
	$(CC) -c $(CCFLAGS) -I $(ARDUINO_DIR) -I $(VARIANTS) -o wiring_shift.o $(ARDUINO_DIR)/wiring_shift.c $(CFLAGS)
clean:
	@echo  "clean...";
	rm -f *.o
	rm -f *.a
	rm -f *.elf
	@echo "done.";
