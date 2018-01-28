CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJS := func.o

all: app.exe

app.exe: $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o app.exe

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< 

clean:	
	rm -rf *.exe *.o
