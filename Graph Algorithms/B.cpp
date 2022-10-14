// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1193
 
#include<iostream>
#include <string>
#include <queue>
#include <algorithm>
 
using namespace std;

bool vis[1005][1005];
char grid[1005][1005];
void BFS();
string findPath();
int n, m;
pair<int,int> start, meta;
pair< pair<int,int>, char > mov[] = {make_pair(make_pair(-1,0), 'U'),make_pair(make_pair(1,0), 'D'),make_pair(make_pair(0,-1), 'L'),make_pair(make_pair(0,1), 'R')};

int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
 
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
			if(grid[i][j]=='A') start = make_pair(i, j);
			if(grid[i][j]=='B') meta = make_pair(i, j);
		}

	BFS();

	if(grid[meta.first][meta.second] == 'B') cout << "NO";
	else{
		cout << "YES" << endl;
		string pp = findPath();
		cout << pp.size() << endl << pp;
	}


	return 0;
}

void BFS(){
	queue< pair<int,int> >path;
	vis[start.first][start.second] = true;

	path.push(make_pair(start.first, start.second));

	while(!path.empty()){
		pair<int,int>cur = path.front();
		path.pop();
		for(int k = 0; k < 4; k++){
			int mx = cur.first + mov[k].first.first;
			int my = cur.second + mov[k].first.second;

			if(mx < 0 || mx >= n || my < 0 || my >= m) continue;
			if(!vis[mx][my] && grid[mx][my] != '#'){
				grid[mx][my] = mov[k].second;
				vis[mx][my] = true;
				path.push(make_pair(mx, my));
			}
			if(meta.first == mx && meta.second == my){
				return;
			}
		}
	}
}

string findPath(){
	pair<int,int> coor = meta;
	string pp;
	while(grid[coor.first][coor.second] != 'A'){
		pp += grid[coor.first][coor.second];
		if(grid[coor.first][coor.second] == 'U') coor.first++;
		else if(grid[coor.first][coor.second] == 'D') coor.first--;
		else if(grid[coor.first][coor.second] == 'L') coor.second++;
		else if(grid[coor.first][coor.second] == 'R') coor.second--;
	}
	reverse(pp.begin(), pp.end());
	return pp;
}
