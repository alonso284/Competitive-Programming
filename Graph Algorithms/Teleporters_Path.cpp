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

/*
procedure FindEulerPath(V)
  1. iterate through all the edges outgoing from vertex V;
       remove this edge from the graph,
       and call FindEulerPath from the second end of this edge;
  2. add vertex V to the answer.
  */
void FindEulerPath(vector<int> &path, vector<vector<int>> &adj, int V){
	while(!adj[V].empty()){
		int U = adj[V].back();
		adj[V].pop_back();
		FindEulerPath(path, adj, U);
	}
	path.push_back(V);
}

void solve(){
	int n; cin >> n;
	int m; cin >> m;

	vector<vector<int>> adj(n);
	vector<int> in(n), out(n);
	for(int i = 0 ; i < m; i++){
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		out[a]++, in[b]++;
	}

	for(int i = 0 ; i < n; i++)
		if(in[i]+(i==0) != out[i]+(i==n-1)){
			cout << "IMPOSSIBLE" << endl;
			return;
		}

	vector<int> path;
	FindEulerPath(path, adj, 0);
	reverse(path.begin(), path.end());

	if((int)path.size() != m+1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	for(const int &V: path) cout << V+1 << ' ';
	
}
