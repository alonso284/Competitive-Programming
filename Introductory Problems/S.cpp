// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1625

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ S.cpp -std=c++17
*/

int t;
bool grid[7][7];
string prete;

void path(int passed, int x, int y){
	if(passed==49 && x==6 && y==0){
		t++;
		return;
	}
	if(passed==49) return;
	if(x==6&&y==0) return;

	if((y>0&&y<6&&grid[x][y-1]==false&&grid[x][y+1]==false&&(x==0||grid[x-1][y]==true)&&(x==6||grid[x+1][y]==true))||
	   (x>0&&x<6&&grid[x-1][y]==false&&grid[x+1][y]==false&&(y==0||grid[x][y-1]==true)&&(y==6||grid[x][y+1]==true)))
		return;

	if((prete[passed-1]=='?'||prete[passed-1]=='R') && y<6 && grid[x][y+1]==false){
		grid[x][y+1]=true;
		path(passed+1, x, y+1);
		grid[x][y+1]=false;
	}

	if((prete[passed-1]=='?'||prete[passed-1]=='L') && y>0 && grid[x][y-1]==false){
		grid[x][y-1]=true;
		path(passed+1, x, y-1);
		grid[x][y-1]=false;
	}

	if((prete[passed-1]=='?'||prete[passed-1]=='D') && x<6 && grid[x+1][y]==false){
		grid[x+1][y]=true;
		path(passed+1, x+1, y);
		grid[x+1][y]=false;
	}

	if((prete[passed-1]=='?'||prete[passed-1]=='U') && x>0 && grid[x-1][y]==false){
		grid[x-1][y]=true;
		path(passed+1, x-1, y);
		grid[x-1][y]=false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	grid[0][0]=true;
	cin >> prete;
	path(1, 0, 0);
	cout << t;

	return 0;
}
