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

bool dfs(const vector<vector<int>> &adj,
         vector<bool> &vis,
         int node,
         int target,
         vector<int> &path
){
    if(node == target){
        path.push_back(node);
        return true;
    }

    vis[node] = true;

    for (int to : adj[node])
        if (!vis[to] && dfs(adj, vis, to, target, path)) {
            path.push_back(node);
            return true;
        }

    return false;
}

void dfs2(
		const vector<vector<int>> &radj,
		int node,
		int ini,
		int &entry_time,
		const vector<int> &d,
		const vector<int> &p,
		vector<bool> &vis
){
	entry_time = min(entry_time, d[node]);
	if(d[node] != INT_MAX && node != ini) return;

	if(vis[node]) return;
	vis[node] = true;

	for(const int &to: radj[node])
		if(to != p[node])
			dfs2(radj, to, ini, entry_time, d, p, vis);
}

void solve(){
	int n; cin >> n;
	int m; cin >> m;

	vector<vector<int>> adj(n+1), radj(n+1);
	while(m--){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	vector<bool> vis(n+1, false);
	vector<int> path;
	dfs(adj, vis, 1, n, path);
	reverse(path.begin(), path.end());

	vector<int> p(n+1);
	vector<int> d(n+1, INT_MAX);
	vis.assign(n+1, false);

	d[1] = 0;
	for(int i = 1; i < path.size(); i++){
		d[path[i]] = i;
		p[path[i]] = path[i-1];
	}

	// cout << "PATH" << endl;
	// for(const int &v: path) cout << v << ' ' << p[v] << ' ' << d[v] << endl;
	// cout << endl;

	vector<int> ans;
	int entry_time = d[path.back()];
	for(int i = path.size()-1; i >= 0; i--){
		if(d[path[i]] <= entry_time) ans.push_back(path[i]);
		dfs2(radj, path[i], path[i], entry_time, d, p, vis);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(const int &v: ans) cout << v << ' ';
	cout << endl;




}
