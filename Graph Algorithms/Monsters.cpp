// Alonso Huerta Escalante
// https://cses.fi/problemset/task/1194

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct coor{
	int x, y, steps;
	coor(int i, int j, int s) { x = i; y = j; steps = s; }
	bool operator==(coor ob) { return this->x == ob.x && this->y == ob.y; }
	void operator-=(int m[2]){
		x -= m[0];
		y -= m[1];
	}
};

int grid[1005][1005];
bool path[1005][1005];
queue <coor> COORS;
int N, M;
void processMonst();
int moves[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
pair<int,int> start;
char dir[4] = {'D', 'U', 'R', 'L'};
coor findEscape();
int dec(char d){
	switch(d){
		case 'D': return 0;
		case 'U': return 1;
		case 'R': return 2;
		case 'L': return 3;
	}
	return -1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			char temp; cin >> temp;
			if(temp == 'A')
				start = {i, j};	
			if(temp =='M')
				 COORS.push({i, j, 0});

			grid[i][j] = (temp=='#'?-1:-2);
			if(temp == 'M') grid[i][j] = 0;
		}

	processMonst();
/* for(int i = 0; i < N; i++){ */
/* 		for(int j = 0; j < M; j++){ */
/* 			cout << grid[i][j]; */
/* 		} */
/* 		cout << endl; */
/* 	} */

	coor res = findEscape();


	if(res == coor(-1,-1,0)){
		cout << "NO";
	}else{
		cout << "YES\n" << res.steps << '\n';
		char P[res.steps];
		for(int i = 0; i < res.steps; i++){
			P[i] = grid[res.x][res.y];
			res -= moves[dec(grid[res.x][res.y])];
		}
		reverse(P, P+res.steps);
		for(int i = 0 ; i < res.steps; i++) cout << P[i];
		
	}

	/* for(int i = 0; i < N; i++){ */
	/* 	for(int j = 0; j < M; j++){ */
	/* 		cout << grid[i][j]; */
	/* 	} */
	/* 	cout << endl; */
	/* } */

	return 0;
}

void processMonst(){
	while(!COORS.empty()){
		coor mtr = COORS.front();
		COORS.pop();
		for(int k = 0; k < 4; k++){
			int movx = mtr.x + moves[k][0];
			int movy = mtr.y + moves[k][1];

			if(movx < 0 || movx >= N || movy < 0 || movy >= M) continue;
			if(grid[movx][movy]==-2){
				COORS.push({movx, movy, mtr.steps + 1});
				grid[movx][movy] = mtr.steps + 1;
			}
		}
		
	}
}

coor findEscape(){
	COORS.push({start.first, start.second, 0});
	while(!COORS.empty()){
		coor player = COORS.front();
		COORS.pop();
		if(player.x == 0 || player.x == N-1 || player.y == 0 || player.y == M-1) return player;
		for(int k = 0; k < 4; k++){
			int movx = player.x + moves[k][0];
			int movy = player.y + moves[k][1];

			if(movx < 0 || movx >= N || movy < 0 || movy >= M) continue;
			if(path[movx][movy] || grid[movx][movy] == -1 ||( player.steps+1 >= grid[movx][movy] && grid[movx][movy] != -2)) continue;
			COORS.push({movx, movy, player.steps + 1});
			grid[movx][movy] = dir[k];
			path[movx][movy] = true;
			
			if(movx == 0 || movx == N-1 || movy == 0 || movy == M-1)
				return {movx, movy, player.steps + 1};
		}
	}
	return {-1,-1,0};
}
