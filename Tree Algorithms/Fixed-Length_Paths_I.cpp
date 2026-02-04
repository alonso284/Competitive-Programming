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

const int MAXN = 200005;
vector<int> adj[MAXN];
int sz[MAXN], cnt[MAXN];
bool vis[MAXN];
long long ans = 0;
int n, k, max_depth;

void get_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p && !vis[v]) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
}

int get_centroid(int u, int p, int total) {
    for (int v : adj[u])
        if (v != p && !vis[v] && sz[v] > total / 2)
            return get_centroid(v, u, total);
    return u;
}

void get_dist(int u, int p, int d, bool filling) {
    if (d > k) return;
    max_depth = max(max_depth, d);

    if (filling)
        cnt[d]++;
    else
        ans += cnt[k - d];

    for (int v : adj[u])
        if (v != p && !vis[v])
            get_dist(v, u, d + 1, filling);
}

void decompose(int u) {
    get_sz(u, -1);
    int centroid = get_centroid(u, -1, sz[u]);
    vis[centroid] = true;

    cnt[0] = 1;
    max_depth = 0;

    for (int v : adj[centroid])
        if (!vis[v]) {
            get_dist(v, centroid, 1, false);
            get_dist(v, centroid, 1, true);
        }

    for (int i = 0; i <= max_depth; i++) cnt[i] = 0;

    for (int v : adj[centroid])
        if (!vis[v]) decompose(v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(1);
    cout << ans << endl;
    return 0;
}
