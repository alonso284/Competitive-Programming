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

vector<bool> strongly_connected_components(vector<vector<int>> const& adj){
    int n = adj.size();
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
	int comp = 0;
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            int root = comp++;
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
	vector<bool> ans(n/2, 0);
    for (int v = 0; v < n; v += 2)
		if (roots[v] != roots[v+1])
			ans[v/2] = roots[v] < roots[v + 1];
		else return vector<bool>();
	return ans;
}

void solve(){
	int n; cin >> n;
	int m; cin >> m;

	vector<vector<int>> adj(m*2);
	while(n--){
		char sx1, sx2; int x1, x2;
		cin >> sx1 >> x1 >> sx2 >> x2;
		x1--, x2--;

		bool nx1 = (sx1 == '+');
		bool nx2 = (sx2 == '+');

		adj[x1<<1|!nx1].push_back(x2<<1|nx2);
		adj[x2<<1|!nx2].push_back(x1<<1|nx1);
	}

	vector<bool> ans = strongly_connected_components(adj);
	if(ans.empty()) cout << "IMPOSSIBLE" << endl;
	else for(const bool &answer: ans) cout << (answer ? '+' : '-') << ' ';
}
