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

void DFS(const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ord, int node){
	vis[node] = true;

	for(const int &next: adj[node])
		if(!vis[next])
			DFS(adj, vis, ord, next);

	ord.push_back(node);
}

int main(){
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> adj(n+1);
	while(m--){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	vector<int> ord(n+1);
	vector<bool> vis(n+1);
	DFS(adj, vis, ord, 1);

	vector<int> paths(n+1, 0);
	paths[n] = 1;
	for(const int &node: ord)
		for(const int &next: adj[node])
			paths[node] += paths[next], paths[node] %= 1000000007;

	cout << paths[1] << endl;
	return 0;
}

