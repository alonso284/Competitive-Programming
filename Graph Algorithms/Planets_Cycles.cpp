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

bool dfs(
		const vector<int> &t, 
		vector<bool> &vis,
		vector<bool> &curr,
		vector<bool> &cycle,
		int node
		){
	if(curr[node]) return cycle[node] = true;
	if(vis[node]) return false;

	vis[node] = true;
	curr[node] = true;

	bool ans = dfs(t, vis, curr, cycle, t[node]);
	bool before = cycle[node];
	cycle[node] = ans;

	curr[node] = false;
	return (before ? false: ans);
}

int dfs(
		const vector<int> &t, 
		vector<int> &ans,
		int node
	   ){
	if(ans[node]) return ans[node];
	else return ans[node] = dfs(t, ans, t[node])+1;
}


int main(){
	int n; cin >> n;
	vector<int> t(n);
	vector<int> in(n);
	for(int &it: t)
		cin >> it, it--, in[it]++;

	vector<bool> vis(n);
	vector<bool> curr(n);
	vector<bool> cycle(n);

	for(int i = 0 ; i < n; i++)
		dfs(t, vis, curr, cycle, i);

	vector<int> ans(n);
	for(int i = 0 ; i < n; i++)
		if(cycle[i] && !ans[i]){
			int size = 1;
			int j = t[i];

			while(j != i){
				size++;
				j = t[j];
			}

			ans[j] = size;
			j = t[i];

			while(j != i){
				ans[j] = size;
				j = t[j];
			}
		}

	for(int i = 0 ; i < n; i++)
		dfs(t, ans, i);

	for(const int &a: ans) cout << a << ' '; cout << endl;





}
