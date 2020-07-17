output: Simple_Calculator.o calculator.o
	gcc Simple_Calculator.o calculator.o -o Simple -lm

Simple_Calculator.o: Simple_Calculator.c
	gcc -c Simple_Calculator.c

calculator.o: calculator.c calculator.h
	gcc -c calculator.c

clean:
	rm *.o Simple