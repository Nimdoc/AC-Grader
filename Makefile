main: main.o grader.o
	g++ -g grader.o main.o -o ac-grader.out
main.o: grader.o
	g++ -g -c main.cpp -o main.o
grader.o: trigram.o
	g++ -g -c grader.cpp -o grader.o
trigram.o:
	g++ -g -c trigram.cpp -o trigram.o
