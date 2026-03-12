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

bool poss = true;
vector<pair<int, int>> edges;
vector<set<int>> adj;
vector<int> level;
int depth = 1;

int dfs(int parent, int node){
	if(level[node]) return level[node];

	int reach = INT_MAX;
	const int my_depth = depth++;
	level[node] = my_depth;
	while(!adj[node].empty()){
		const int to = *adj[node].begin();
		adj[node].erase(to);
		adj[to].erase(node);

		edges.push_back({node, to});
		reach = min(reach, dfs(node, to));
	}

	if(1 < my_depth && my_depth <= reach) poss = false;

	return level[node] = reach;
}

int main(){
	int n; cin >> n;
	int m; cin >> m;
	adj.resize(n+1);
	level.resize(n+1);

	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}


	dfs(0, 1);
	if(poss && (int)edges.size() == m) for(const auto &[from, to]: edges) cout << from << ' ' << to << endl;
	else cout << "IMPOSSIBLE";

}
