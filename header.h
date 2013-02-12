#ifndef HEADRE_H
#define HEADER_H
#include<vector>
enum res{WIN,GO,NEXT};

struct box{
	int val;
	bool flags;
	bool open;
	box();
};

class minearena{
	box **arena;
	int high, weigh;
	void open(int x, int y);
	bool none(int x, int y);
	void open_map();
	void end();
	bool win();
	bool test_mine(int x, int y);

public:
//	minearena();
	minearena(int h, int w,int m);
	void print();
	res process(int x, int y);
	~minearena();
};
	
#endif
