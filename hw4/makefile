OBJS = hw4.o  

CC = gcc
FLAGS = -Wall 

all : driver 
	./driver < ../comments.txt

driver : driver.c mylib.a 
	$(CC) $(FLAGS) -o $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<


mylib.a : $(OBJS)
	ar cr $@ $^
clean :
	rm -f $(OBJS) *.a driver 
