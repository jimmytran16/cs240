OBJS = hw8.o 
arg = cs240.csv

CC = gcc 
FLAGS = -Wall 

clean : all
	rm -f $(OBJS) *.a 

all : driver 
	./driver $(arg)


driver : driver.c $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -lm

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<