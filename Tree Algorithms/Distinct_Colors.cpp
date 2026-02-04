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

pair<int, int> dfs(
		const vector<vector<int>> &adj,
		vector<unordered_set<int>> &c,
		vector<int> &ans,
		int node,
		int parent
		){

	pair<int, int> l = {(int)c[node].size(), node};
	for(const int &to: adj[node])
		if(to != parent)
			l = max(l, dfs(adj, c, ans, to, node));

	swap(c[node], c[l.second]);

	for(const int &to: adj[node])
		if(to != parent)
			for(const int &color: c[to])
				c[node].insert(color);

	ans[node] = c[node].size();
	return {(int)c[node].size(), node};

}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<unordered_set<int>> c(n);
	for(int i = 0; i < n; i++){
		int color; cin >> color;
		c[i].insert(color);
	}
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> ans(n);
	dfs(adj, c, ans, 0, -1);
	for(const int &answer: ans)
		cout << answer << ' ';
	cout << endl;
}

