// Code by $%U%$ $%Y%$
#include <iostream>
#include <complex>
#include <bitset>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;



#define SIZE 8
int grid[SIZE][SIZE];
const pair<int, int> moves[] = {{+1, +2}, {-1, +2}, {+1, -2}, {-1, -2}, {+2, +1}, {-2, +1}, {+2, -1}, {-2, -1}};

int available(int x, int y){
	int next = 0;
	for(const auto &[dx, dy]: moves)
		if(x+dx < 0 || x+dx >= SIZE || y+dy < 0 || y+dy >= SIZE || grid[x+dx][y+dy]) continue;
		else next++;
	return next;
}

bool dfs(int x, int y, int t){
	grid[x][y] = t;

	if(t == SIZE*SIZE) return true;

	vector<pair<int, pair<int, int>>> next;
	for(const auto &[dx, dy]: moves)
		if(x+dx < 0 || x+dx >= SIZE || y+dy < 0 || y+dy >= SIZE || grid[x+dx][y+dy]) continue;
		else next.push_back({available(x+dx, y+dy), {x+dx, y+dy}});
	sort(next.begin(), next.end());

	for(const auto &[m, coor]: next){
		const auto &[x, y] = coor;
		if(dfs(x, y, t+1)) return true;
	}

	grid[x][y] = 0;
	return false;
}

int main(){
	int x, y; cin >> x >> y; x--, y--;
	swap(x, y); dfs(x, y, 1);

	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
}
