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

int dfs(const vector<vector<int>> &adj, int node, int parent, int &ans){
	const int n = adj.size();

	int subtreesum = 0;
	bool candidate = true;
	for(const int &to: adj[node])
		if(to != parent){
			int size = dfs(adj, to, node, ans);
			if(size > n/2) candidate = false;
			subtreesum += size;
		}

	if(n-subtreesum-1 > n/2) 
		candidate = false;
	
	if(candidate) ans = node;
	return subtreesum+1;
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = -1;
	dfs(adj, 0, -1, ans);
	cout << ans+1 << endl;
}
