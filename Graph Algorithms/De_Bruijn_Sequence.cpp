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

void solve();

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

bool dfs(const int n, const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &path, int node){
	if(path.size() == adj.size()){
		for(int i = 0; i < n; i++) cout << 0;
		for(int i = 1; i < (int)path.size(); i++) cout << (path[i]&1); 
		cout << endl;
		return true;
	}

	for(const int &to: adj[node])
		if(!vis[to]){
			path.push_back(to);
			vis[to] = true;
			if(dfs(n, adj, vis, path, to)) return true;
			path.pop_back();
			vis[to] = false;
		}

	return false;
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(1<<n);

	for(int i = 1; i < (1<<n)-1; i++){
		adj[i].push_back((i<<1) & ((1<<n)-1));
		adj[i].push_back((i<<1|1) & ((1<<n)-1));
	}

	adj[0].push_back(1);
	adj[(1<<n)-1].push_back((1<<n)-2);

	vector<bool> vis(1<<n);
	vector<int> path = {0};
	vis[0] = true;

	dfs(n, adj, vis, path, 0);
}
