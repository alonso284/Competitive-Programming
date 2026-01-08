#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;


#define MAXM 1001
#define MAXN 10
const int64_t MOD = 1000000007;

int n, m;
bool poss(const bitset<MAXN> &a, const bitset<MAXN> &b){
	for(int bit = 0; bit < n; bit++){
		// if a == 1, then b == 0, then wrong
		if(a[bit]){
			if(b[bit]) return false;
		} else {
			// if a == 0, then b == 1 is possible
			if(b[bit]) continue;
			// if a == 0, and b == 0 is possible if bit+1 is 0 in both
			if(bit+1 >= n || a[bit+1] || b[bit+1]) return false;
			bit++;
		}
	}
	return true;
}

int64_t dp[1<<MAXN][MAXM];
bool vis[1<<MAXN][MAXM];
vector<vector<int>> adj(1ll<<MAXN);
int64_t DP(int mask, int left){
	if(left == 0) return mask == 0;
	
	if(vis[mask][left]) return dp[mask][left];
	vis[mask][left] = true;
	int64_t &ans = dp[mask][left];
	for(int const &next: adj[mask])
		ans += DP(next, left-1), ans %= MOD;
	return dp[mask][left];
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < (1ll<<n); i++)
	{
		bitset<MAXN> a(i);
		for(int j = 0; j < (1ll<<n); j++)
		{
			bitset<MAXN> b(j);
			if(!poss(a, b)) continue;
			adj[i].push_back(j);
		}
	}

	cout << DP(0, m) << endl;

	return 0;
}
