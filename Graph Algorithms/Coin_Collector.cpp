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

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongly_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *component.begin();
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

vector<int64_t> dp;
vector<int64_t> k;
int64_t dfs(const vector<vector<int>> &adj_cond, int v){
	if(visited[v]) return dp[v];
	visited[v] = true;

	for(const int &to: adj_cond[v])
		dp[v] = max(dp[v], dfs(adj_cond, to));
	return dp[v] += k[v];
}

int main(){
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> adj(n);
	vector<vector<int>> components;
	vector<vector<int>> adj_cond;

	vector<int64_t> a(n);
	for(int64_t &it: a)
		cin >> it;

	while(m--){
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
	}

	strongly_connected_components(adj, components, adj_cond);

	k.assign(n, 0);
	visited.assign(n, false);
	dp.assign(n, 0);
	for(int c = 0; c < components.size(); c++)
		for(const int &v: components[c])
			k[components[c].front()] += a[v];

	int64_t ans = 0;
	for(int c = 0; c < n; c++)
		ans =  max(ans, dfs(adj_cond, c));

	cout << ans << endl;

	return 0;
}
