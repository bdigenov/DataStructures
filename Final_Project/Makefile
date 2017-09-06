CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		custom standard
test:       custom standard test-output-standard test-output-custom test-scaling-standard test-scaling-custom test-cache-helpfulness-standard test-cache-helpfulness-custom

custom:     jokebot.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

standard:   redditbot.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test-output-standard:    standard
	@echo "Testing standard map (Correctness)..."
	@rm -f joke.txt
	@touch joke.txt
	@./standard joke1.txt > standardResult.txt
	@diff -q standardResult.txt correctnessExpected.txt
	@rm -f joke.txt
	@rm -f standardResult.txt
	@touch joke.txt

test-output-custom:     custom
	@echo "Testing custom map (Correctness)..."
	@rm -f joke.txt 
	@touch joke.txt 
	@./custom joke1.txt > customResult.txt 
	@diff -q customResult.txt correctnessExpected.txt 
	@rm -f joke.txt 
	@rm -f customResult.txt 
	@touch joke.txt 


test-scaling-standard:   standard
	@echo "Testing standard map scaling (Time)... "
	@rm -f joke.txt 
	@touch joke.txt 
	@echo "---------------------Standard---------------------"
	@echo "---1 Word: "
	@( time ./standard joke1.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---5 Word: "
	@( time ./standard joke5.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---10 Word: "
	@( time ./standard joke10.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---20 Word: "
	@( time ./standard joke20.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---50 Word: "
	@( time ./standard joke50.txt ) | tail -n 1

test-scaling-custom:    custom
	@echo "Testing custom map scaling (Time)... "
	@rm -f joke.txt
	@touch joke.txt
	@echo "---------------------Custom---------------------"
	@echo "---1 Word: "
	@( time ./custom joke1.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---5 Word: "
	@( time ./custom joke5.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---10 Word: "
	@( time ./custom joke10.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---20 Word: "
	@( time ./custom joke20.txt ) | tail -n 1
	@rm -f joke.txt
	@touch joke.txt
	@echo "---50 Word: "
	@( time ./custom joke50.txt ) | tail -n 1

test-cache-helpfulness-standard:     standard
	@echo "Testing cache helpfulness with standard map (Time)... "
	@rm -f joke.txt
	@touch joke.txt
	@echo "---Standard w/o Cache:  "
	@echo "------1 Word: "
	@( time ./standard joke1.txt ) | tail -n 1
	@echo "------5 Word: "
	@( time ./standard joke5.txt ) | tail -n 1
	@echo "------10 Word: "
	@( time ./standard joke10.txt ) | tail -n 1
	@echo "---Standard w/ Cache:  "
	@( time ./standard joke1.txt ) | tail -n 1
	@( time ./standard joke5.txt ) | tail -n 1
	@( time ./standard joke10.txt ) | tail -n 1

test-cache-helpfulness-custom:      custom
	@echo "Testing cache helpfulness with custom map (Time)... "
	@rm -f joke.txt
	@touch joke.txt
	@echo "---Custom w/o Cache:  "
	@echo "------1 Word: "
	@( time ./custom joke1.txt ) | tail -n 1
	@echo "------5 Word: "
	@( time ./custom joke5.txt ) | tail -n 1
	@echo "------10 Word: "
	@( time ./custom joke10.txt ) | tail -n 1
	@echo "---Custom w/ Cache:  "
	@( time ./custom joke1.txt ) | tail -n 1
	@( time ./custom joke5.txt ) | tail -n 1
	@( time ./custom joke10.txt ) | tail -n 1


clean:
	rm -f standard custom
