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

bool DFS(const vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &cur, vector<int> &ord, int &timer, int node){
	if(cur[node]) return true;
	if(vis[node]) return false;
	vis[node] = true;
	cur[node] = true;
	for(const int &next: adj[node])
		if(DFS(adj, vis, cur, ord, timer, next))
			return true;
	ord[timer++] = node;
	cur[node] = false;
	return false;
}

int main(){
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> adj(n+1);
	while(m--){
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
	}

	int timer = 0;
	vector<int> ord(n);
	vector<bool> vis(n+1);
	vector<bool> cur(n+1);
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			if(DFS(adj, vis, cur, ord, timer, i)){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}

	for(const int &it: ord) cout << it << ' ';
	cout << endl;
	return 0;
}
