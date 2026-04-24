CC = g++
CCFLAG = -g -w
project4: main.o Computing.o Experiment.o
	$(CC) $(CCFLAG) -o project4 main.o Computing.o Experiment.o
main.o: main.C Experiment.h Computing.h
	$(CC) $(CCFLAG) -c -o main.o main.C
Computing.o: Computing.C Computing.h
	$(CC) $(CCFLAG) -c -o Computing.o Computing.C
Experiment.o: Experiment.C Experiment.h
	$(CC) $(CCFLAG) -c -o Experiment.o Experiment.C

clean:
	rm -rf project4 *.o
