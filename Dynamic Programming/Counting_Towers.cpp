// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/2413

#include<iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

const int MAXN = 1000006;
const int MOD = 1e9+7;
long long dp[MAXN][10];
int n;

// de abajo para arriba
// 0 -> 0, 1, 2
// 1 -> 0, 1, 2
// 3 -> 0, 1, 2
// 2 -> 3, 4, 5, 6, 7
// 4 -> 3, 4, 5, 6, 7
// 5 -> 3, 4, 5, 6, 7
// 6 -> 3, 4, 5, 6, 7
// 7 -> 3, 4, 5, 6, 7



long long DP(int l, int t){
	if(l == 1) return 1;
	if(dp[l][t]) return dp[l][t];

	switch(t){
		case 0:
		case 1:
		case 3:
			// 0, 1, 2
			dp[l][t] = 	DP(l-1, 0) + 
						DP(l-1, 1) +
						DP(l-1, 2);
			break;
		case 2:
		case 4:
		case 5:
		case 6:
		case 7:
			// 3, 4, 5, 6, 7
			dp[l][t] = 	DP(l-1, 3) + 
						DP(l-1, 4) +
						DP(l-1, 5) +
						DP(l-1, 6) +
						DP(l-1, 7);
			break;
	}

	dp[l][t] %= MOD;

	return dp[l][t];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		cin >> n;

		if(n==1){
			cout << 2 << endl;
			continue;
		}

		long long ans = 0;
		for(int i = 0; i < 8; i++)
			ans += DP(n-1, i);

		ans %= MOD;

		cout << ans << endl;
	}

	return 0;
}


