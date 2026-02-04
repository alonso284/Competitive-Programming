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
	ts[order] = a[node];
	order++;

	for(const int &to: adj[node])
		if(to != parent)
			dfs(adj, a, order, in, out, ts, to, node);

	out[node] = order-1;
}

struct FenwickTree {
    vector<int64_t> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int64_t> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int64_t sum(int r) {
        int64_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int64_t sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int64_t delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

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

	FenwickTree ft(ts);
	int cmd, s;
	int64_t x, delta;
	while(q--){
		cin >> cmd;
		switch(cmd){
			case 1:
				cin >> s >> x; s--;
				delta = x-a[s];
				ft.add(in[s], delta);
				a[s] = ts[in[s]] = x;
				break;
			case 2:
				cin >> s; s--;
				cout << ft.sum(in[s], out[s]) << endl;
				break;
		}
	}
}
