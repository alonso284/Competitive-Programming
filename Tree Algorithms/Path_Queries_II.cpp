// Code by $%U%$ $%Y%$
#include <iostream>
#include <cassert>
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

#define MAXN 200005
void solve();

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int vals[MAXN], list[MAXN];
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
	fill(heavy, heavy + n, -1);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

int N;
int seg[2 * MAXN];

void build(int arr[], int n) {
    N = n;

    for (int i = 0; i < N; i++)
        seg[N + i] = arr[i];

    for (int i = N - 1; i > 0; i--)
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

int query_seg(int l, int r) {
    int res = 0;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (!(r & 1)) res = max(res, seg[r--]);
    }
    return res;
}

void update_seg(int pos, int val) {
    for (seg[pos += N] = val; pos > 1; pos >>= 1)
        seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = query_seg(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = query_seg(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

void solve(){
	int n; cin >> n;
	int q; cin >> q;
	for(int i = 0 ; i < n; i++) cin >> vals[i];

	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	init(adj);

	for(int v = 0; v < n; v++)
		list[pos[v]] = vals[v];
	build(list, n);

	int cmd, s, x, a, b;
	while(q--){
		cin >> cmd;
		switch(cmd){
			case 1:
				cin >> s >> x; s--;
				update_seg(pos[s], x);
				break;
			case 2:
				cin >> a >> b; a--, b--;
				cout << query(a, b) << '\n';
				break;
		}
	}
}
