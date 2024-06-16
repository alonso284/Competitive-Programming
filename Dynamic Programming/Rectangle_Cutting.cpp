#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[505][505];
int INF = 1005;

int DP(int a, int b){
	if(a < b) swap(a, b);
	if(a == b) return 0;
	if(!dp[a][b]){
		dp[a][b] = INF;
		for(int i = 1; i < a; i++)
			dp[a][b] = min(dp[a][b], DP(i, b) + DP(a-i, b) + 1);

		for(int i = 1; i < b; i++)
			dp[a][b] = min(dp[a][b], DP(a, i) + DP(a, b-i) + 1);
	}
	return dp[a][b];
}

int main(){

	int a, b; cin >> a >> b;
	/* memset(dp, INF, sizeof(dp)); */
	cout << DP(a, b);

	return 0;
}
