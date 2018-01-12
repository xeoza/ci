CC:=gcc -std=c99
CKEYS:= -Wall -Werror -pedantic -c
OKEYS:= -o

app.exe: main.o io.o
	$(CC) $(OKEYS) $@ $^

%.o: %.c func.h structs.h
	$(CC) $(CKEYS) $^

clean:
	rm *.exe *.o
