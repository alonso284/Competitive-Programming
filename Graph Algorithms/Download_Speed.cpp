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

int n;
vector<vector<int64_t>> capacity;
vector<vector<int>> adj;
const int64_t INF = LLONG_MAX;

int64_t bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int64_t>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int64_t flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int64_t new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int64_t maxflow(int s, int t) {
    int64_t flow = 0;
    vector<int> parent(n);
    int64_t new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
	cin >> n;
	int m; cin >> m;
	adj.resize(n);
	capacity.assign(n, vector<int64_t>(n));

	while(m--){
		int a, b; cin >> a >> b; a--, b--;
		int64_t c; cin >> c;
		capacity[a][b] += c;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << maxflow(0, n-1);

}
