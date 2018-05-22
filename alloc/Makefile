CXXFLAGS=-std=c++17

all: fast slow
fast: test.cpp alloc.hpp
	clang++ ${CXXFLAGS} -DOPTIMIZED test.cpp -o fast
slow: test.cpp alloc.hpp
	clang++ ${CXXFLAGS} test.cpp -o slow

.PHONY: all
