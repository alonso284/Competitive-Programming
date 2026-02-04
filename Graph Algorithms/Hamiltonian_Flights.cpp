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

const int64_t MOD = 1000000007;
int64_t dp[20][(1<<20)];
bool vis[20][(1<<20)];
int n;
vector<int> adj[20];

int64_t DP(int node, int mask){
	if(node == n-1) return __builtin_popcount(mask) == n;

	bool &v = vis[node][mask];
	int64_t &ans = dp[node][mask];
	if(v) return ans;
	v = true;

	for(const int &to: adj[node])
		if(!(mask & (1<<to)))
			ans += DP(to, mask|(1<<to)),
			ans %= MOD;

	return ans;
}

int main(){
	cin >> n;
	int m; cin >> m;

	while(m--){
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
	}

	cout << DP(0, 1) << '\n';
}
