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

#define MAXN 200005
int n, k1, k2;
vector<int> adj[MAXN];
int subtree[MAXN];

int64_t ans = 0;
int total_cnt[MAXN]{1}, mx_depth;
int cnt[MAXN], subtree_depth;
bool vis[MAXN];

int get_subtree_sizes(int node, int parent = 0) {
	subtree[node] = 1;
	for (const int &to : adj[node])
		if (!vis[to] && to != parent) subtree[node] += get_subtree_sizes(to, node);
	return subtree[node];
}

int get_centroid(int desired, int node, int parent = 0) {
	for (const int &to : adj[node])
		if (!vis[to] && to != parent && subtree[to] >= desired)
			return get_centroid(desired, to, node);
	return node;
}

void get_cnt(int node, int parent, int depth = 1) {
	if (depth > k2) return;
	subtree_depth = max(subtree_depth, depth);
	cnt[depth]++;
	for (const int &to : adj[node])
		if (!vis[to] && to != parent) get_cnt(to, node, depth + 1);
}

void centroid_decomp(int node = 1) {
	int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
	vis[centroid] = true;

	mx_depth = 0;
	int64_t partial_sum_init = (k1 == 1 ? 1ll: 0ll);
	for (const int &to : adj[centroid])
		if (!vis[to]) {
			subtree_depth = 0;
			get_cnt(to, centroid);

			int64_t partial_sum = partial_sum_init;
			for (int depth = 1; depth <= subtree_depth; depth++) {
				ans += partial_sum * cnt[depth];

				int dremove = k2 - depth;
				if (dremove >= 0) partial_sum -= total_cnt[dremove];
				int dadd = k1 - (depth + 1);
				if (dadd >= 0) partial_sum += total_cnt[dadd];
			}

			for (int depth = k1 - 1; depth <= k2 - 1 && depth <= subtree_depth; depth++)
				partial_sum_init += cnt[depth];

			for (int depth = 1; depth <= subtree_depth; depth++)
				total_cnt[depth] += cnt[depth];
			mx_depth = max(mx_depth, subtree_depth);

			fill(cnt, cnt + subtree_depth + 1, 0);
		}

	fill(total_cnt + 1, total_cnt + mx_depth + 1, 0);
	for (const int &to : adj[centroid])
		if (!vis[to]) centroid_decomp(to);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k1 >> k2;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid_decomp();
	cout << ans;
	return 0;
}
