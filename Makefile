main: main.o grader.o
	g++ -std=c++11 -g grader.o main.o trigram.o -o ac-grader.out
main.o: grader.o
	g++ -std=c++11 -g -c main.cpp -o main.o
grader.o: trigram.o
	g++ -std=c++11 -g -c grader.cpp -o grader.o
trigram.o:
	g++ -std=c++11 -g -c trigram.cpp -o trigram.o
