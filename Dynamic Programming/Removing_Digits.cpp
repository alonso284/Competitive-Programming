// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1637

#include<iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MOD = 1e9+7;
const int INF = INT_MAX;
int DP[1000001];

int dp(int n){
	if(DP[n] == -1){
		DP[n] = INF;
		int dec = n;
		while(dec){
			if(dec%10)
				DP[n] = min(DP[n], dp(n-dec%10)+1);
			dec /= 10;
		}
	}
	return DP[n];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, -1, sizeof(DP));
	DP[0] = 0;

	int n; cin >> n;
	cout << dp(n);

	return 0;
}


