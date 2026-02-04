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

void dfs(
		const vector<vector<int>> &adj, 
		const vector<int64_t> &a,
		int &order,
		vector<int> &in, 
		vector<int> &out, 
		vector<int64_t> &ts, 
		int node, 
		int parent
){
	in[node] = order;
	ts[order] = (parent != -1 ? ts[in[parent]] : 0) + a[node];
	order++;

	for(const int &to: adj[node])
		if(to != parent)
			dfs(adj, a, order, in, out, ts, to, node);

	out[node] = order-1;
}

#define MAXN 200005
int64_t t[4*MAXN], marked[4*MAXN];

void build(const vector<int64_t> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void push(int v, int tl, int tr) {
    if (marked[v]) {
		int tm = (tl + tr) / 2;
		if(tl == tm) t[v*2] += marked[v];
		if(tm+1 == tr) t[v*2+1] += marked[v];

        marked[v*2] += marked[v];
		marked[v*2+1] += marked[v];
        marked[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int64_t delta) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
		if(tl == tr) t[v] += delta;
        marked[v] += delta;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), delta);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, delta);
    }
}

int64_t get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

void solve(){
	int n; cin >> n;
	int q; cin >> q;

	vector<int64_t> a(n);
	for(int64_t &it: a) cin >> it;

	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> in(n), out(n);
	vector<int64_t> ts(n);
	int order = 0;
	dfs(adj, a, order, in, out, ts, 0, -1);
	build(ts, 1, 0, n-1);

	int cmd, s;
	int64_t x, delta;
	while(q--){
		cin >> cmd;
		switch(cmd){
			case 1:
				cin >> s >> x; s--;
			 	delta = x-a[s];
				ts[in[s]] = a[s] = x;
				update(1, 0, n-1, in[s], out[s], delta);
				break;
			case 2:
				cin >> s; s--;
				cout << get(1, 0, n-1, in[s]) << endl;
				break;
		}
	}
}
