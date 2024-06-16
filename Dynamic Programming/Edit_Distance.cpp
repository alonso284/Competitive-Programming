#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 5005;
const int INF = MAXN * MAXN;
int dp[MAXN][MAXN];
string n, m;

int min(int a, int b, int c, int d){
	return min(min(a, b), min(c, d));
}

int DP(int i, int j){
	if(j == m.size() || i == n.size()) return m.size() - j + n.size() - i;
	if(dp[i][j] != -1) return dp[i][j];

	// is equal
	if(n[i] == m[j])
		dp[i][j] = DP(i+1, j+1);
	else
		dp[i][j] = INF;

	// remove
	// add
	// replace
	dp[i][j] = min(
			dp[i][j],
			DP(i+1, j+1)+1, 	// replace
			DP(i, j+1) 	+1, 	// add
			DP(i+1, j)	+1); 	// remove
	
	return dp[i][j];
}


int main(){
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0);

	return 0;
}
