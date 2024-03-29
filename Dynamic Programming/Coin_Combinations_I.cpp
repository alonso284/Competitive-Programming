// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1635

#include<iostream>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int MOD = 1e9+7;
int DP[1000001];
int coins[MAXN];
int n, x;

int dp(int money){
	if(money < 0) return 0;
	if(DP[money] == -1){
		DP[money] = 0;
		for(int i = 0; i < n; i++){
			DP[money] += dp(money-coins[i]);
			DP[money] %= MOD;
		}
	}
	return DP[money];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, -1, sizeof(DP));
	DP[0] = 1;

	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> coins[i];
	cout << dp(x);

	return 0;
}


