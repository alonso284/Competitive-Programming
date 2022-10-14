// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1192

#include<iostream>

using namespace std;

int movs[4][2] = {{-1, 0},{1,0},{0,-1},{0,1}};
char CountingRooms[1000][1000];
bool vis[1000][1000];
void DFS(int i, int j);
int c;
int n, m; 

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> CountingRooms[i][j];

	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis[i][j] && CountingRooms[i][j]=='.'){
				c++;
				DFS(i, j);
			}
	cout << c;	
	return 0;
}

void DFS(int i, int j){
	vis[i][j] = true;
	
	for(int p = 0; p < 4; p ++){
		int mx = i + movs[p][0];
		int my = j + movs[p][1];
		if(mx < 0 || mx >= n || my < 0 || my >= m) continue;
		if(!vis[mx][my] && CountingRooms[mx][my]=='.')
			DFS(mx, my);
 	}
}

