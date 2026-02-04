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

pair<int64_t, int> operator+(const pair<int64_t, int> f, const pair<int64_t, int> s){
	return {f.first+s.first, f.second+s.second};
}

pair<int64_t, int> dfs(const vector<vector<int>> &adj, vector<int> &s, int node, int parent){
	pair<int64_t, int> ans = {0, 0};
	for(const int &to: adj[node])
		if(to != parent)
			ans = ans + dfs(adj, s, to, node);

	ans.first += ans.second;
	ans.second++;

	s[node] = ans.second;

	return ans;
}

void dfs_complete(const vector<vector<int>> &adj, vector<int> &s, vector<int64_t> &d, int node, int parent){
	const int n = adj.size();
	if(parent != -1)
		d[node] = d[parent] - s[node] + (n-s[node]);

	for(const int &to: adj[node])
		if(to != parent)
			dfs_complete(adj, s, d, to, node);
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> s(n);
	vector<int64_t> d(n);
	d[0] = dfs(adj, s, 0, -1).first;
	dfs_complete(adj, s, d, 0, -1);

	for(const int64_t &ans: d) cout << ans << ' ';
	cout << endl;
}
