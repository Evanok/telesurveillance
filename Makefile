CC=avr-g++
ROMEO_DIR=romeo_src
ROMEO_SRC=$(ROMEO_DIR)/romeo.c
ROMEO_OBJ=$(ROMEO_DIR)/romeo.o
PWD=$(shell pwd)
PATH_TO_ARDUINO_CORE=$(PWD)/arduino_core/
ROMEO_DIR=romeo_src
FLAGS=-g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=22



romeo:
	@echo "build romeo sources...";
	$(CC) -c $(FLAGS) -I $(PATH_TO_ARDUINO_CORE) -o $(ROMEO_OBJ) $(ROMEO_SRC)
	@echo " done.";

clean:
	@echo  "clean...";
	rm -f $(ROMEO_OBJ);
	@echo "done.";
