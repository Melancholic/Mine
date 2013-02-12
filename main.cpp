#include<iostream>
#include<stdlib.h>
#include"header.h"
int main(){
	int h=10,w=10,m=9;
	system("clear");
	std::cout<<"\n\t\t\tКОНСОЛЬНЫЙ САПЕР";
	std::cout<<"\n Тип игры 1 -- по умолчанию, 2 -- свои параметры, ваш выбор: ";
	int menu1;
	while(1){
		std::cin>>menu1;
		if(menu1==1 || menu1 ==2) break; else{
			std::cout<<"\nНеверный ввод. Введите данные повторно : ";
		}
	}
	if (menu1==2){
		std::cout<<"\nВведите высоту поля: ";
		std::cin>>h;
		std::cout<<"\nВведите ширину поля: ";
		std::cin>>w;
		std::cout<<"\nВведите кол-во мин: ";
		std::cin>>m;
	}
	minearena MineArena(h,w,m);
	res menu=NEXT;
	while(menu==NEXT){
		system("clear");
		std::cout<<"\t\t\t КОНСОЛЬНЫЙ САПЕР\n";
		MineArena.print();
		std::cout<<"\n Введите x y: ";
		int x,y;
		std::cin>>x>>y;
		menu=MineArena.process(x,y);
	}
	return 0;
}
		
		
