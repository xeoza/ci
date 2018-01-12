CC := gcc

CFLAGS := -std=gnu99 -ggdb -Wall -pedantic 

OBJS := functions.o 

all : test.exe 

test.exe : $(OBJS) tests.o tests_my_strlen.o tests_my_strdup.o tests_my_strspn.o
	$(CC) $(CFLAGS) $^ -o test.exe

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf *.o *.exe
