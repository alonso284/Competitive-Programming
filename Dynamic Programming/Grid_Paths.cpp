// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1638

#include<iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

const int MAXN = 105;
const int MOD = 1e9+7;
int DP[1003][1003];
int n;

vector<string> grid;

int dp(int i = 0, int j = 0){
	if(grid[i][j] == '*') return DP[i][j] = 0;

	if(DP[i][j] == -1) DP[i][j] = dp(i, j+1) + dp(i+1, j);
	return DP[i][j] %= MOD;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, -1, sizeof(DP));
	cin >> n;
	DP[n-1][n-1] = 1;
	grid.resize(n+1);
	for(int i = 0; i < n; i++){
		cin >> grid[i];
		grid[i]+='*';
	}
	grid[n] = string(n+1, '*');
	cout << dp();


	return 0;
}


