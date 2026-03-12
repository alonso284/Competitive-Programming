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

vector<vector<pair<int, int>>> adj;
vector<int> tin;
vector<bool> vis;
int ans = INT_MAX;

void dfs(int node, int parent, int timer){
	if(tin[node]){
		ans = min(ans, timer-tin[node]);
		return;
	}

	tin[node] = timer;
	for(const auto &[to, idx]: adj[node])
		if(to != parent && !vis[idx]){
			vis[idx] = true;
			dfs(to, node, timer+1);
			vis[idx] = false;
		}
	tin[node] = 0;
}

int main(){
	int n; cin >> n;
	int m; cin >> m;
	tin.resize(n+1);
	adj.resize(n+1);
	vis.resize(m);
	for(int idx = 0; idx < m; idx++){
		int a, b; cin >> a >> b;
		adj[a].push_back({b, idx});
		adj[b].push_back({a, idx});
	}

	for(int i = 1; i <= n; i++)
		dfs(i, 0, 1);

	cout << (ans == INT_MAX ? -1 : ans) << endl;
}
