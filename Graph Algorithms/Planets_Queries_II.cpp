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

bool dfs(
		const vector<int> &t, 
		vector<bool> &vis,
		vector<bool> &curr,
		vector<bool> &cycle,
		int node
		){
	if(curr[node]) return cycle[node] = true;
	if(vis[node]) return false;

	vis[node] = true;
	curr[node] = true;

	bool ans = dfs(t, vis, curr, cycle, t[node]);
	bool before = cycle[node];
	cycle[node] = ans;

	curr[node] = false;
	return (before ? false: ans);
}

void rdfs(
		const vector<vector<int>> &adj,
		const vector<pair<int, int>> &cycle,
		const vector<int> &cycle_size,
		const vector<vector<pair<int, int>>> &queries,
		vector<int> &dist,
		vector<int> &ans,
		const int root,
		int d,
		int node
		){
	// cout << root << " -> " << node << endl;
	dist[node] = d;

	for(const auto &[to, idx]: queries[node]){
		// cout << "CHEKING" << ' ' << node << ' ' << to << endl;
		// if this node is on a cycle and is on the same cycle as my root...
		if(cycle[to].first != -1 && cycle[to].first == cycle[root].first){
			// cout << "GOING TO CYCLE" << ' ' << node << ' ' << to << endl;
			ans[idx] = dist[node]-dist[root];
			int cycle_distance = cycle[to].second - cycle[root].second;
			if(cycle_distance < 0) cycle_distance += cycle_size[cycle[root].first];
			ans[idx] += cycle_distance;
		}
		// or if this node is a parent
		else if(cycle[to].first == -1 && dist[to] != -1){
			// cout << "GOING TO PARENT" << ' ' << node << ' ' << to << endl;
			ans[idx] = dist[node] - dist[to];
		}
	}

	// visit next
	for(const int &to: adj[node])
		if(cycle[to].first == -1)
			rdfs(adj, cycle, cycle_size, queries, dist, ans, root, d+1, to);

	dist[node] = -1;
}


int main(){
	int n; cin >> n;
	int q; cin >> q;
	vector<int> t(n);
	vector<int> in(n);
	for(int &it: t)
		cin >> it, it--, in[it]++;

	vector<vector<pair<int, int>>> queries(n);
	vector<int> ans(q, -1);
	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; a--, b--;
		queries[a].push_back({b, i});
	}

	vector<bool> vis(n);
	vector<bool> curr(n);
	vector<bool> cycle(n);

	for(int i = 0 ; i < n; i++)
		dfs(t, vis, curr, cycle, i);

	vector<pair<int, int>> cycle_position(n, {-1, -1});
	vector<int> cycle_size;
	for(int i = 0 ; i < n; i++)
		if(cycle[i] && cycle_position[i].first == -1){
			const int cycle_count = (int)cycle_size.size();
			int pos = 0;
			int j = i;

			do {
				cycle_position[j] = {cycle_count, pos};
				pos++, j = t[j];
			} while(j != i);

			cycle_size.push_back(pos);
		}

	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++)
		adj[t[i]].push_back(i);

	// cout << "CYCLE POSITIONS" << endl;
	// for(int i = 0 ; i < n; i++)
	// 	cout << i << ':' << ' ' << cycle_position[i].first << ' ' << cycle_position[i].second << endl;

	vector<int> dist(n, -1);
	for(int i = 0 ; i < n; i++)
		if(cycle_position[i].first != -1)
			rdfs(adj, cycle_position, cycle_size, queries, dist, ans, i, 1, i);

	for(const int &answer: ans) cout << answer << endl;

}
