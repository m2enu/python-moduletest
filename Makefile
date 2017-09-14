CC := gcc
TARGET := calc
TARGET_TEST := hex2dec
LIBPYTHON := /usr/include/python2.7

.PHONY: all clean hex2dec

all:
	$(CC) -Wall -fPIC -c $(TARGET).c -I$(LIBPYTHON) && \
	$(CC) -shared -o $(TARGET).so $(TARGET).o -lpython2.7

clean:
	rm -rf $(TARGET).o $(TARGET_TEST).o

hex2dec:
	$(CC) $(TARGET_TEST).c -o $(TARGET_TEST).o
