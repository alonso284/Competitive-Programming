// Code by $%U%$ $%Y%$
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

void solve();

int main(){
	solve();
	return 0;
}

vector<vector<pair<int64_t,pair<int,int>>>> dp;
pair<int64_t,pair<int,int>> LCS(const vector<int> &a, const vector<int> &b, int i, int j){
	if(i == a.size() || j == b.size()) return {0, {i, j}};

	pair<int64_t,pair<int,int>> &ans = dp[i][j];
	if(ans.first == -1){
		ans = max(LCS(a, b, i+1, j), LCS(a, b, i, j+1));
		if(a[i]==b[j])
			ans = max(ans, {LCS(a,b,i+1,j+1).first+1, {i,j}});
	}

	return ans;
}

void solve(){
	int n; cin >> n;
	int m; cin >> m;

	vector<int> a(n);
	for(int &it: a)
		cin >> it;
	vector<int> b(m);
	for(int &it: b)
		cin >> it;

	dp.assign(n, vector<pair<int64_t,pair<int,int>>>(m, {-1ll,{-1,-1}}));
	pair<int64_t, pair<int,int>> ans = LCS(a, b, 0, 0);
	cout << ans.first << endl;
	while(ans.second.first != n && ans.second.second != m)
		cout << a[ans.second.first] << ' ', ans = LCS(a, b, ans.second.first+1, ans.second.second+1);
	cout << endl;
}
