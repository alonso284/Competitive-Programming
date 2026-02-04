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

pair<int, vector<int>> bfs(const vector<vector<int>> &adj, int node){
	const int n = adj.size();

	queue<int> q;
	q.push(node);

	vector<int> p(n, -1);
	vector<int> d(n, -1);

	p[node] = node;

	pair<int, int> ans = {0, node};
	while(!q.empty()){
		int node = q.front(); q.pop();

		d[node] = d[p[node]] + 1;
		ans = max(ans, pair<int,int>({d[node], node}));

		for(const int &to: adj[node])
			if(p[to] == -1)
				q.push(to), p[to] = node;
	}

	return {ans.second, d};
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	const int limit = bfs(adj, 0).first;
	const auto [limit2, d2] = bfs(adj, limit);
	const auto [limit1, d1] = bfs(adj, limit2);

	for(int i = 0 ; i < n; i++)
		cout << max(d1[i], d2[i]) << ' ';


}
