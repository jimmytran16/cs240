OBJS = hw5.o  

CC = gcc -g
FLAGS = -Wall 

all : driver 
	./driver 

driver : driver.c mylib.a 
	$(CC) $(FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<


mylib.a : $(OBJS)
	ar cr $@ $^
clean :
	rm -f $(OBJS) *.a driver 