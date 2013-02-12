#include"header.h"
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <ctype.h>

box::box(){
	val=0;
	flags=false;
	open=false;
}
/*
minearena::minearena(){
	minearena(10,10,9);// bad idea
}
*/ 
minearena::minearena(int h, int w,int m){
	high=h;
	weigh=w;
	int val;
	arena= new box* [w];
	for(int i=0;i!=w;++i){
		arena[i]=new box[h];
	}

	srand(time(0));
	for(int i=0;i!=m;++i){
		int x=random()%(w-1);
		int y=random()%(h-1);
		arena[x][y].flags=true;
	}
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			if(!arena[i][j].flags){
				val=0;
				if(test_mine(--i,--j))val++;
                                if(test_mine(i,--j))val++;
                                if(test_mine(--i,j))val++;
                                if(test_mine(++i,++j))val++;
                                if(test_mine(i,++j))val++;
                                if(test_mine(++i,j))val++;
	  			arena[i][j].val=val;
			}
		}
	}
}

bool minearena::none(int x, int y){
	if((x>=0)&&(x<weigh)){
		if((y>=0)&&(y<high)){
			if(arena[x][y].val==0) return true;
		}
	}
	return false;
}
	
bool minearena::test_mine(int x, int y){
	if((x>=0)&&(x<weigh)){
		if((x>=0)&&(x<high)){
			if(arena[x][y].flags)return true;
		}
	}
	return false;
}


void minearena::open(int x, int y){
	if((x>=0)&&(x<weigh)){
		if((y>=0)&&(y<high)){
			if(!arena[x][y].open){
				arena[x][y].open=true;
				if(arena[x][y].val==0){
					open(--x,--y);
                                        open(x,--y);
                                        open(x,++y);
                                        open(++x,--y);
                                        open(++x,++y);
                                        open(--x,++y);
                                        open(--x,y);
                                        open(++x,y);
				}else{
                                         
					if(none(--x,--y)) open(--x,--y);
                                        if(none(x,--y)) open(x,--y);
                                        if(none(x,++y)) open(x,++y);
                                        if(none(++x,--y))  open(++x,--y);
                                        if(none(++x,++y)) open(++x,++y);
                                        if(none(--x,++y)) open(--x,++y);
                                        if(none(--x,y)) open(--x,y);
                                        if(none(++x,y)) open(++x,y);
				}
			}
		}
	}
}

bool minearena::win(){
	for(int i=0;i<weigh;++i){
		for(int j=0;j<high;++j){
			if((!arena[i][j].flags) && (!arena[i][j].open)) return false;
		}
	}
	return true;
}

void minearena::open_map(){
	for(int i=0;i<weigh;++i){
		for(int j=0;j<high;++j){
			if(arena[i][j].flags)arena[i][j].open=true;
		}
	}
}

void minearena::end(){
    system("clear");
    print();
    if(win())
        std::cout<<"\n\n"<<"\tCONGRATILATION, YOU WIN! ^___^\n\n";
    else
        std::cout<<"\n\n"<<"\tSorry, game over =(\n\n";
}

void minearena::print(){
	std::cout << "  \t";
	for(int i=0; i<weigh; i++){
		std::cout << i+1 << " ";
	}
	std::cout<<"\n\n\n\n";
	for(int i=0; i<weigh; i++){
        	std::cout << i+1 <<"\t";
        	for(int j=0; j<high; j++){
			if(arena[i][j].open){
                		if(arena[i][j].flags){ 
                    			std::cout << "* ";
                		}else{
					if(arena[i][j].val == 0){ 
                        			std::cout << ". ";
                			}else{ 
                    				std::cout << arena[i][j].val << " ";
					}	
				}
			}else{            
				std::cout<<"# ";
			}	
        	}	
        		std::cout<<"\n";
	}
}	


		
res minearena::process(int x, int y){
	x--;y--;//Поправка на [0]. Не забыть!!!!
	open(x,y);
	if(arena[x][y].flags){
		open_map();
		end();
		return GO;
	}
	if(win()){
		end();
		return WIN;
	}
	return NEXT;
}
		


minearena::~minearena(){
	for(int i=0;i!=weigh;++i){
		delete[] arena[i];
	}
	delete[] arena;
}


	
