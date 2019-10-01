#CC=gcc
CC=arm-linux-gnueabihf-gcc

all: test01
	
test01: test01.c
	$(CC) -o test01 test01.c -ljson-c -I$(JSONC_INC) -L$(JSONC_LIB)

clean:
	@rm -rf test01

.PHONY: clean
