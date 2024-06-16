#include <iostream>

using namespace std;

int const MAXN = 505;
int const MAXSUM = MAXN*MAXN/4;
int const MOD = 1e9+7;
int S, n;

long long dp[MAXSUM][MAXN];
bool vis[MAXSUM][MAXN];

long long DP(int indx, int sum){
	if(sum == S) return 1;
	if(sum > S || indx == n+1) return 0;

	if(!vis[sum][indx]){
		vis[sum][indx] = true;
		dp[sum][indx] = DP(indx+1, sum+indx) + DP(indx+1, sum);
		dp[sum][indx] %= MOD;
	}

	return dp[sum][indx];
}

int main(){

	cin >> n;
	S = n*(n+1)/2;
	if(S%2){
		cout << 0 << endl;
		return 0;
	}

	S /= 2;
	cout << (DP(1, 0) * 500000004) % MOD << endl;

	return 0;
}
