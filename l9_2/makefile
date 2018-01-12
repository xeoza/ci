CC := gcc

CFLAGS := -std=gnu99 -ggdb -Wall -pedantic 

OBJS := functions.o 

all : app.exe test.exe

app.exe : $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o app.exe

test.exe: $(OBJS) test.o
	$(CC) $(CFLAGS) $^ -o test.exe
    
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf *.o *.exe
