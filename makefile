# makefile for problem 3
#
#	$@ target
# $< first prerequisite
# $^ all prerequisites

flags = -std=c++17 -Wall -I .

problem3functions.o : problem3functions.cpp problem3functions.h
	g++ $(flags) -c $<

testNumDigits : testNumDigits.cpp problem3functions.o
	g++ $(flags) $^ -o $@
	./$@

testFindAndReplace : testFindAndReplace.cpp problem3functions.o
	g++ $(flags) $^ -o $@
	./$@

clean :
	rm problem3functions.o testNumDigits testFindAndReplace

