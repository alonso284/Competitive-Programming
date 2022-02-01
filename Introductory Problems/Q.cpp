// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1624

#include <iostream>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ Q.cpp -std=c++17
*/

char boards[8][8];
bool diagonal1[15], diagonal2[15], column[8];
int Q;

int firstD(int x, int y){
	return x+y;
}

int secondD(int x, int y){
	return x+(7-y);
}

void placeQueen(int row){
	if(row==8){
		Q++;
		return;
	}

	for(int i=0;i<8;i++){
		if(boards[row][i]=='.' && !diagonal1[firstD(row,i)] && !diagonal2[secondD(row,i)] && !column[i]){
			diagonal1[firstD(row,i)] = diagonal2[secondD(row,i)] = column[i] = true;
			placeQueen(row+1);
			diagonal1[firstD(row,i)] = diagonal2[secondD(row,i)] = column[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			cin >> boards[i][j];


	placeQueen(0);
	cout << Q;

	return 0;
}
