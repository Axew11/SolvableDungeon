a.out: main.cc tree.h
	g++ -g -lcurl -O3 -std=c++11 main.cc
