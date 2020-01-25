CC = g++

TESTDIR = test

CCFLAGS = -Wall -Werror -wextra

all: lab8

lab8: main.o lab8.o
	$(CC) -o $@ $^ $(CCFLAGS)
	cp $@ $(TESTDIR)

main.o: main.cpp interface.h
	$(CC) -o $@ $^ $(CCFLAGS)

lab8.o: lab8.cpp interface.h
	$(CC) -c -o $@ $< $(CCFLAGS)