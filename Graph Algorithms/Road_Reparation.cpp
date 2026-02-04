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

vector<int> parent, RANK;

void make_set(int v) {
    parent[v] = v;
    RANK[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (RANK[a] < RANK[b])
            swap(a, b);
        parent[b] = a;
        if (RANK[a] == RANK[b])
            RANK[a]++;
    }
}

struct Edge {
    int u, v;
	int64_t weight;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

int main(){
	int n; cin >> n;
	int m; cin >> m;

	vector<Edge> edges(m);
	for(Edge &e: edges) cin >> e.u >> e.v >> e.weight;

	int64_t cost = 0;
	vector<Edge> result;
	parent.resize(n+1);
	RANK.resize(n+1);
	for (int i = 1; i <= n; i++)
		make_set(i);

	sort(edges.begin(), edges.end());

	for (Edge e : edges) {
		if (find_set(e.u) != find_set(e.v)) {
			cost += e.weight;
			result.push_back(e);
			union_sets(e.u, e.v);
		}
	}

	if(result.size() < n-1){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << cost << endl;

}
