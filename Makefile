all: cmem cppmem
cmem: memory.c
	clang memory.c -o cmem
cppmem: memory.cpp
	clang++ -std=c++17 memory.cpp -o cppmem

.PHONY: all
