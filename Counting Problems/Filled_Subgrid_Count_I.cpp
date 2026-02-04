// Code by $%U%$ $%Y%$
#include <iostream>
#include <complex>
#include <bitset>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

void solve();

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	vector<string> grid(n);
	vector<vector<int>> dp(n, vector<int>(n));

	for(string &row: grid)
		cin >> row;

	vector<int64_t> ans(m, 0);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		if((i && j) && grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i-1][j-1])
			dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
		else
			dp[i][j] = 1;

		ans[grid[i][j]-'A'] += dp[i][j];
	}

	for(const int64_t &res: ans)
		cout << res << endl;
}
