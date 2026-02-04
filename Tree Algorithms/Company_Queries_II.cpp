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

vector<pair<int, int>> t;

void build(int v, int tl, int tr, const vector<int> &path, const vector<int> &h) {
    if (tl == tr) {
        t[v] = {h[tl], path[tl]};
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm, path, h);
        build(v*2+1, tm+1, tr, path, h);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

pair<int, int> getmin(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {INT_MAX, INT_MAX};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(getmin(v*2, tl, tm, l, min(r, tm)), getmin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void dfs(const vector<vector<int>> &adj, vector<int> &path, vector<int> &h, vector<int> &idx, int node, int l){
	idx[node] = path.size();

	path.push_back(node);
	h.push_back(l);

	for(const int &to: adj[node]){
		dfs(adj, path, h, idx, to, l+1);
		path.push_back(node);
		h.push_back(l);
	}
}

void solve(){
	int n; cin >> n;
	int q; cin >> q;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int p; cin >> p; p--;
		adj[p].push_back(i);
	}

	vector<int> path, h;
	vector<int> idx(n, -1);

	dfs(adj, path, h, idx, 0, 0);

	const int m = path.size();
	t.resize(m * 4);
	build(1, 0, m-1, path, h);

	while(q--){
		int u, v; cin >> u >> v; u--, v--;
		int l = min(idx[u], idx[v]);
		int r = max(idx[u], idx[v]);
		cout << getmin(1, 0, m-1, l, r).second + 1 << endl;
	}
}
