CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ llrec-test.cpp llrec.cpp


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 