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

const int INF = INT_MAX;
const pair<int, int> INFP = {INF, INF};

int build_next(
		const vector<vector<int>> &adj,
		vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> &next,
		int node
		){

	if(!next[node].empty()) return next[node].top().first;

	next[node].push({node, node});
	for(const int &to: adj[node]){
		int smallest_in_subtree = build_next(adj, next, to);
		next[node].push({smallest_in_subtree, to});
	}

	return next[node].top().first;
}

// if smallest[node] == node, empty myself out
// else, 
int erase(
		const vector<vector<int>> &adj,
		vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> &next,
		int node
		){

	if(next[node].empty()) return 0;
	// cout << "-> " << node << endl;

	bool empty = false;
	while(!next[node].empty()){
		const auto [smallest_in_subtree, to] = next[node].top(); next[node].pop();

		if(to == node){
			empty = true;
			continue;
		}

		int new_smallest_in_subtree = erase(adj, next, to);
		if(new_smallest_in_subtree) next[node].push({new_smallest_in_subtree, to});

		if(!empty) return next[node].top().first;
	}

	cout << node << ' ';
	return 0;
}

int main(){
	int n; cin >> n;
	int m; cin >> m;

	vector<vector<int>> adj(n+1);
	while(m--){
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
	}

	// cout << "BUILDING" << endl;
	vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> next(n+1);
	for(int i = 1; i <= n; i++)
		build_next(adj, next, i);

	// cout << "ERASING" << endl;
	for(int i = 1; i <= n; i++)
		erase(adj, next, i);
}
