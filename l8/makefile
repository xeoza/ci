#Compilation
CC := gcc

#Options
CFLAGS := -std=c99 -ggdb -Wall -Werror -pedantic 

#Object files
OBJS := functions.o

all: app.exe test.exe 

app.exe : $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o app.exe -lm

test.exe : $(OBJS) test.o tests_summ.o tests_determination.o tests_multiplication.o
	$(CC) $(CFLAGS) $^ -o test.exe -lm

time.exe : $(OBJS) time.o
	$(CC) $(CFLAGS) $^ -o time.exe -lm
	
%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -rf *.o *.exe
