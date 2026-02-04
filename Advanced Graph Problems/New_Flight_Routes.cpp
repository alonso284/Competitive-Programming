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

	for(vector<int> &v: adj_cond){
		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
	}
}

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
	vector<pair<int, int>> pairs;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;

            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    bool dfs2(int v, vector<int> &path) {
        if (v == t)
            return true;

        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;

			if(id & 1) continue;

			if(edges[id].flow == 1 && dfs2(u, path)){
				edges[id].flow = 0;
        		if (u != t)
					path.push_back(u);
				return true;
			}
        }
        return false;
    }

    long long flow() {
        long long f = 0;
        while (true) {
			vector<int> path;
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }

        fill(ptr.begin(), ptr.end(), 0);
		vector<int> path;
		while(dfs2(s, path)){
			pairs.push_back({path.front(), path.back()});
			path.clear();
		}
        return f;
    }
};

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	const int s = 0, t = n+1;
	vector<vector<int>> adj(n+2);

	while(m--){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	for(vector<int> &v: adj){
		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
	}

	vector<vector<int>> components;
	vector<vector<int>> adj_cond;
	strongly_connected_components(adj, components, adj_cond);

	if(components.size() == 1+2){
		cout << 0 << endl;
		return;
	}

	Dinic dinic(n+2, s, t);

	vector<bool> in(n+2), out(n+2);
	for(int i = 0; i < components.size(); i++){
		const int u = components[i].front();
		if(u == s || u == t) continue;

		out[u] = !adj_cond[u].empty();
		for(const int &v: adj_cond[u])
			dinic.add_edge(u, v, 1), in[v] = true;
	}

	for(int i = 0; i < components.size(); i++){
		const int u = components[i].front();
		if(u == s || u == t) continue;

		if(!in[u])  dinic.add_edge(s, u, 1);
		if(!out[u]) dinic.add_edge(u, t, 1);
	}

	const int p = dinic.flow();

	vector<pair<int, int>> edges;
	const vector<pair<int, int>> &pairs = dinic.pairs;

	for(int i = 0; i < pairs.size(); i++){
		int j = (i+1)%pairs.size();

		const int s = pairs[i].second;
		const int e = pairs[j].first;

		in[s] = true,
		out[e] = true,

		edges.push_back({e, s});
	}

	vector<int> roots, leafs;
	for(int i = 0; i < components.size(); i++){
		const int u = components[i].front();
		if(u == s || u == t) continue;

		if(!in[u]) roots.push_back(u);
		if(!out[u]) leafs.push_back(u);
	}

	while(!roots.empty() && !leafs.empty()){
		const int u = leafs.back(); leafs.pop_back();
		const int v = roots.back(); roots.pop_back();
		edges.push_back({u, v});
	}

	const auto &[E, S] = pairs.front();
	while(!roots.empty()){
		const int v = roots.back(); roots.pop_back();
		edges.push_back({E, v});
	}

	while(!leafs.empty()){
		const int u = leafs.back(); leafs.pop_back();
		edges.push_back({u, S});
	}

	cout << edges.size() << endl;
	for(const auto &[u, v]: edges)
		cout << u << ' ' << v << endl;
}
