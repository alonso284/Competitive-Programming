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
#include <limits>
#include <cfloat>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

void solve();

const int MOD = 1000000007;

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

struct FenwickTree {
    vector<int64_t> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int64_t sum(int r) {
        int64_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r], ret %= MOD;
        return ret;
    }

    int64_t sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int64_t delta) {
		delta %= MOD;
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta, bit[idx] %= MOD;
    }
};

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	set<int> s;
	for(int &it: a)
		cin >> it, s.insert(it);
	map<int,int> m;
	int c = 0;
	for(const int &it: s)
		m[it] = c++;
	for(int &it: a)
		it = m[it];


	FenwickTree ft(n+1);
	vector<int> dp(n);
	int64_t ans = 0;
	for(int i = n-1; i >= 0; i--){
		dp[i] = ft.sum(a[i]+1, n) + 1;
		ft.add(a[i], dp[i]);
		ans += dp[i];
		ans %= MOD;
	}
	if(ans < 0) ans += MOD;
	cout << ans << endl;

}
