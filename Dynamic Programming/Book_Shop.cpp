// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1158

#include<iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

const int MAXN = 1003;
const int MAXX = 100005;
const int MOD = 1e9+7;
int s[MAXN], h[MAXN];
int n, x;

int DP[MAXN][MAXX];
bool vis[MAXN][MAXX];
int dp(int indx = 0, int money = 0){
	if(money > x) return INT_MIN;
	if(indx == n) return 0;

	if(!vis[indx][money])
		DP[indx][money] = max(dp(indx+1, money), dp(indx+1, money+h[indx]) + s[indx]);
	vis[indx][money] = true;

	return DP[indx][money];
}

/* int DP[MAXX]; */

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> s[i];
	cout << dp();

	/* for(int i = n-1; i >= 0; i--){ */
	/* 	for(int j = 0; j <= x; j++){ */
	/* 		if(j + h[i] <= x) */
	/* 			DP[j] = max(DP[j], DP[j+h[i]]+s[i]); */
	/* 		else */ 
	/* 			DP[j] = DP[j]; */
	/* 	} */
	/* } */

	/* cout << DP[0]; */




	return 0;
}


