// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1746

#include<iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

const int MAXN = 100005;
const int MAXM = 102;
const int MOD = 1e9+7;
int DP[2][MAXM];
int n, x[MAXN], m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> x[i];

	if(!x[n-1]) for(int i = 1; i <= m; i++) DP[0][i] = 1;
	else DP[0][x[n-1]] = 1;

	for(int i = n-2; i >= 0; i--){
		swap(DP[0], DP[1]);

		for(int j = 1; j <= m; j++){
			if(x[i] == 0) DP[0][j] = (DP[1][j-1] + DP[1][j])%MOD + DP[1][j+1];
			else if(j == x[i]) DP[0][j] = (DP[1][j-1] + DP[1][j])%MOD + DP[1][j+1];
			else DP[0][j] = 0;
			DP[0][j] %= MOD;
		}
	}

	long long sum = 0;
	for(int i = 0; i <= m; i++) sum += DP[0][i];
	cout << sum % MOD;

	return 0;
}


