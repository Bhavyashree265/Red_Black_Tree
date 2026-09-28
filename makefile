OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
rbt.out: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o *.exe