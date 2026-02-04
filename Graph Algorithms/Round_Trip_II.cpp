// Code by $%U%$ $%Y%$
#include <iostream>
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

int DFS(const vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &cur, vector<int> &p, int parent, int node){
	p[node] = parent;
	if(cur[node]) return node;
	if(vis[node]) return 0;
	vis[node] = true;
	cur[node] = true;

	int s = 0;
	for(const int &next: adj[node])
		if(s = DFS(adj, vis, cur, p, node, next))
			return s;

	cur[node] = false;
	return 0;
}


int main(){
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> adj(n+1);
	while(m--){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> vis(n+1);
	vector<bool> cur(n+1);
	vector<int> p(n+1, -1);
	int s = 0;
	for(int i = 1; i <= n && !s; i++)
		if(!vis[i])
			s = DFS(adj, vis, cur, p, -1, i);

	if(!s){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<int> ans;
	do {
		ans.push_back(s);
		s = p[s];
	} while(ans.front() != s);
	ans.push_back(s);


	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(const int &it: ans) cout << it << ' ';
}
