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

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int &it: a)
		cin >> it;

	map<int,int> f;
	int64_t ans = 0;
	int i = 0;
	for(int j = 0; j < n; j++){
		f[a[j]]++;
		while(f[a[j]] > 1)
			f[a[i++]]--;
		ans += j-i+1;	
	}
	cout << ans << endl;
}
