# use g++ with c+17 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -std=c++17
OUTFILES?=Main

all: $(OUTFILES)

Main: Main.cpp Tree.cpp Tree.hpp BinarySearchTree.cpp BinarySearchTree.hpp
	$(CXX) $(CXXFLAGS) -o Main.exe Main.cpp Tree.cpp BinarySearchTree.cpp


clean:
	$(RM) $(OUTFILES) *.o *.exe