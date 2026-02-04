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

int main(){
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<pair<int, int64_t>>> adj(n+1);
	while(m--){
		int a, b; cin >> a >> b;
		int64_t c; cin >> c;
		adj[a].push_back({b, c});
	}

	priority_queue<pair<int64_t, int>> pq;

	vector<int64_t> d(n+1, LLONG_MAX);
	vector<int> MIN(n+1);
	vector<int> MAX(n+1);
	vector<int> PATH(n+1);
	d[1] = 0;
	PATH[1] = 1;

	using pii = pair<int64_t, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, 1});

	while (!q.empty()) {
		int v = q.top().second;
		int64_t d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int64_t len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				MIN[to] = MIN[v]+1;
				MAX[to] = MAX[v]+1;
				PATH[to] = PATH[v];
				q.push({d[to], to});
			}
			else if (d[v] + len == d[to]) {
				MIN[to] = min(MIN[to], MIN[v]+1);
				MAX[to] = max(MAX[to], MAX[v]+1);
				PATH[to] += PATH[v];
				PATH[to] %= 1000000007;
			}
		}
	}
	cout << d[n] << ' ' << PATH[n] << ' ' << MIN[n] << ' ' << MAX[n] << endl;
	return 0;
}
