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

int DFS(const vector<vector<int>> &adj, int node, vector<int> &s){
	for(int sub: adj[node])
		s[node] += DFS(adj, sub, s);
	return s[node]+1;
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++){
		int p; cin >> p; p--;
		adj[p].push_back(i);
	}

	vector<int> s(n);
	DFS(adj, 0, s);

	for(const int r: s) cout << r << ' ';
	cout << endl;
	
}
