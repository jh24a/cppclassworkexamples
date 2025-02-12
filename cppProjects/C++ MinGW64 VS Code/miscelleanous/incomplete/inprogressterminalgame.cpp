#include <iostream>
#include "header.h"
#include <chrono>
#include <iomanip>
#include <cstdlib>
using namespace std;

int const VIEW_PORT_ROW = 26;
int const VIEW_PORT_COL = 33;
char array[26][33];
int x = 12;
int y = 15;


void fill(int, int , Object [],char array[26][33]);
void playerpos(int&, int&);
void makeScene(Object objects[10]);
void draw(char array[26][33]);

int main() {
	Object objects[10];
	makeScene(objects);
	while (true) {
		draw(array)
		fill(VIEW_PORT_ROW, VIEW_PORT_COL, objects,array);
		//draw(array);
		playerpos(x, y);
	}


	return 0;
}
/************************************/
void playerpos(int& x, int& y) {
	char action = cin.get();
	switch (action)
	{
	case 'w':
		--y;
		break;
	case 's':
		++y;
		break;
	case 'a':
		--x;
		break;
	case 'd':
		++x;
		break;
	default:
		break;
	}
}
/************************************/
void fill(int row, int col, Object objects[] , char array[26][33]) {
	int counter;
	for (int i = 0; i < row; i++) {
		array[i][0] = i;
		counter = 0;
		for (int j = 0; j < col; j++) {
			
			if (i == objects[counter].y && j == objects[counter].x){
				array[i][j] = 'X';
			}
			else if (i == y && j == x) 
				cout << setw(3) << "@";
			else if (i == 0 || i == row - 1)
				cout << setw(3) << j ;
			else
				cout << setw(3) << "  ";
			if (counter < 10)
				counter++;	
		}
		cout << setw(3) << "|";
		cout << endl;
	}
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}
/*
void draw(char array[VIEW_PORT_ROW][VIEW_PORT_COL]){
	int counter;
	for (int i = 0; i < row; i++) {
		cout << setw(3) << i;
		counter = 0;
		for (int j = 0; j < col; j++) {
			
			if (i == objects[counter].y && j == objects[counter].x){
				cout << setw(3) << "X";
			}
			else if (i == y && j == x) 
				cout << setw(3) << "@";
			else if (i == 0 || i == row - 1)
				cout << setw(3) << j ;
			else
				cout << setw(3) << "  ";
			if (counter < 10)
				counter++;	
		}
		cout << setw(3) << "|";
		cout << endl;
	}
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}
*/
/*************************************/
void makeScene(Object objects[10]){
	srand(time(0));
	
	for (int i = 0; i < 10; ++i){
		objects[i].x = rand() % VIEW_PORT_ROW + 1;
		objects[i].y = rand() % VIEW_PORT_COL + 1;
		cout << "x: " << objects[i].x << "   y: " << objects[i].y << endl;
}	}
