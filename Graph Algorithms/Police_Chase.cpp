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

const int INF = INT_MAX;
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

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

set<int> S;
void dfs(int v){
	if(S.count(v)) return;
	S.insert(v);

	for(const int &to: adj[v])
		if(capacity[v][to])
			dfs(to);
}

int main(){
	cin >> n;
	int m; cin >> m;
	adj.resize(n);
	capacity.assign(n, vector<int>(n));
	while(m--){
		int a, b; cin >> a >> b; a--, b--;
		capacity[a][b]++;
		capacity[b][a]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << maxflow(0, n-1) << endl;
	dfs(0);
	for(const int &v: S)
		for(const auto &to: adj[v])
			if(!S.count(to))
				cout << v+1 << ' ' << to+1 << endl;
}
