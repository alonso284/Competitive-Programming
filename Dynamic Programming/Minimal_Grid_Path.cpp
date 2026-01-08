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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}

const vector<pair<int,int>> delta = {{0,+1},{+1,0}};

void solve(){
	int n; cin >> n;

	vector<string> grid(n);
	for(string &row: grid)
		cin >> row;

	vector<pair<int,int>> q;
	q.push_back({0, 0});
	string res;
	res += grid[0][0];
	while(!q.empty()){
		vector<pair<int,int>> next;
		char best = 'Z'+1;
		for(const auto &[x, y]: q){
			for(const auto &[dx, dy]: delta)
				if(x+dx < n && y+dy < n){
					if(grid[x+dx][y+dy] < best) next.clear(), best = grid[x+dx][y+dy];
					if(grid[x+dx][y+dy] == best) next.push_back({x+dx, y+dy}), grid[x+dx][y+dy] = 'Z'+1;
				}
		}
		swap(next, q);
		if(!q.empty()) res += best;
	}
	cout << res << endl;

}
