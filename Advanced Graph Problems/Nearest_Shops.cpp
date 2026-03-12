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
const int INF = 1e9;

int main() {
   	int n, m, k;
    cin >> n >> m >> k;

   	vector<int> special_cities(k);
	vector<int> dist(n, -1);
	vector<int> source(n, -1);
	queue<int> q;

    for (int i = 0; i < k; i++) {
		cin >> special_cities[i];
		special_cities[i]--;
		dist[special_cities[i]] = 0;
		source[special_cities[i]] = special_cities[i];
		q.push(special_cities[i]);
    }

   	vector<vector<int>> adj(n);
   	for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
   	}

   	vector<int> ans(n, INF);

   	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (source[v] == -1) {
 				dist[v] = dist[u] + 1;
 				source[v] = source[u];
 				q.push(v);
			} else if (source[v] != source[u]) {
 				int total_dist = dist[u] + dist[v] + 1;
 				ans[source[u]] = min(ans[source[u]], total_dist);
                ans[source[v]] = min(ans[source[v]], total_dist);
			}
        }
    }

	for (int i = 0; i < k; i++)
		dist[special_cities[i]] = (ans[special_cities[i]] == INF ? -1 : ans[special_cities[i]]);

	:or(const int &answer: dist) cout << answer << ' '; cout << endl;

    return 0;
}
