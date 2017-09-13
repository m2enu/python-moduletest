CC := gcc
TARGET := calc
LIBPYTHON := /usr/include/python2.7

.PHONY: all clean

all:
	$(CC) -Wall -fPIC -c $(TARGET).c -I$(LIBPYTHON) && \
	$(CC) -shared -o $(TARGET).so $(TARGET).o -lpython2.7

clean:
	rm -rf $(TARGET).o
