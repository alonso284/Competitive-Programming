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
vector<set<int>> adj;

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

int main(){
	int N; cin >> N;
	int M; cin >> M;
	int k; cin >> k;

	n = N+M+2;
	int s = 0;
	int t = N+M+1;

	adj.resize(n);
	capacity.assign(n, vector<int>(n));

	for(int a = 1; a <= N; a++){
		adj[s].insert(a);
		adj[a].insert(s);
		capacity[s][a] = 1;
	}

	for(int b = N+1; b <= N+M; b++){
		adj[t].insert(b);
		adj[b].insert(t);
		capacity[b][t] = 1;
	}

	while(k--){
		int a, b; cin >> a >> b;
		b += N;
		capacity[a][b] = 1;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	cout << maxflow(s, t) << endl;
	for(int a = 1; a <= N; a++)
		if(capacity[s][a] == 0)
			for(const int &b: adj[a])
				if(capacity[a][b] == 0)
					cout << a << ' ' << b-N << endl;
}
