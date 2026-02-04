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

vector<vector<int>> adjog;
bool dfs(int v, set<int> &vis, vector<int> &path){
	if(v == n-1){
		path.push_back(v);
		return true;
	}

	vis.insert(v);
	for(const int &to: adjog[v])
		if(capacity[v][to] == 0)
			if(dfs(to, vis, path)){
				capacity[v][to] = 1;
				path.push_back(v);
				return true;
			}

	return false;
}


int main(){
	cin >> n;
	int m; cin >> m;

	adj.resize(n);
	adjog.resize(n);
	capacity.assign(n, vector<int>(n));

	while(m--){
		int a, b; cin >> a >> b;
		capacity[--a][--b] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
		adjog[a].push_back(b);
	}

	int paths = maxflow(0, n-1);
	cout << paths << endl;
	while(paths--){
		vector<int> path;
		set<int> vis;
		dfs(0, vis, path);
		reverse(path.begin(), path.end());
		cout << path.size() << endl;
		for(const int &it: path) cout << it+1 << ' ';
		cout << endl;
	}



}
