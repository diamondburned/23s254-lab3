CXX ?= g++
CXXFLAGS ?= $(shell cat compile_flags.txt)

main.out: *.cpp *.hpp
	$(CXX) $(CXXFLAGS) -o main.out *.cpp
