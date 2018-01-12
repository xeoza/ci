CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJS := list_func.o

app.exe : $(OBJS) main.o
	$(CC) $^ -o $@

#time_test.exe : $(OBJS) time_test.o
	#$(CC) $^  -o $@
	
#test.exe : $(OBJS) unit_test.o
	#$(CC) $^  -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS)  -c $<
clean : 
	rm *.o *.exe

