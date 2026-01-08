// Code by $%U%$ $%Y%$
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

void solve();

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

const vector<pair<int, int>> moves = {{+2,+1},{+2,-1},{-2,+1},{-2,-1},{+1,+2},{+1,-2},{-1,+2},{-1,-2}};

void solve(){
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
	int filled = 0;
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {0, 0}});
	while(filled < n*n){
		auto const [s, coor] = q.front(); q.pop();
		auto const &[i, j] = coor;
		if(min(i, j) < 0 || max(i, j) >= n || grid[i][j] <= s) continue;
		grid[i][j] = s;
		filled++;

		for(const auto &[di, dj]: moves)
			q.push({s+1,{i+di,j+dj}});
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << grid[i][j] << ' ';
		cout << endl;
	}
}
