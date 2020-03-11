exe = a.out
option = -Wall -std=c99

run : $(exe)
	./$(exe) < CompleteShakespeare.txt 

$(exe): histo.c
	gcc -o $@ $^ $(option)
clean:
	rm  $(exe)
