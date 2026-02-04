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

void solve(){
	int n; cin >> n;

	vector<set<int>> adj(n);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v; u--, v--;

		adj[u].insert(v);
		adj[v].insert(u);
	}

	queue<int> q;
	for(int v = 0; v < n; v++)
		if(adj[v].size() == 1) q.push(v);

	int ans = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();
		if(adj[v].empty()) continue;
		ans++;
		int u = *adj[v].begin();

		for(int to: adj[u]){
			adj[to].erase(u);
			if(adj[to].size() == 1)
				q.push(to);
		}
		adj[u].clear();

		for(int to: adj[v]){
			adj[to].erase(v);
			if(adj[to].size() == 1)
				q.push(to);
		}
		adj[v].clear();

	}

	cout << ans << endl;

}
