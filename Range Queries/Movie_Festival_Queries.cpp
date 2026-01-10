// Code by $%U%$ $%Y%$
#include <iostream>
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

struct FenwickTreeMin {
    vector<pair<int,int>> bit;
    int n;
    const pair<int,int> INF = {(int)1e9, INT_MAX};

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<pair<int,int>> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    pair<int,int> getmin(int r) {
        pair<int,int> ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

	void update(int idx, pair<int,int> val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};


int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n; cin >> n;
	int q; cin >> q;
	vector<pair<int, int>> ar(n);
	for(auto &[a, b]: ar)
		cin >> a >> b;

	sort(ar.begin(), ar.end());

	vector<pair<int,int>> ends(n+1);
	ends.front() = pair<int,int>({(int)1e6+1, n});
	for(int i = 0; i < n; i++) ends[n-i] = {ar[i].second, i};
	FenwickTreeMin ft(ends);

	int nlog2 = 32 - __builtin_clz(n);
	vector<vector<int>> next(n, vector<int>(nlog2));
	for(int i = 0 ; i < n; i++){
		int idx = lower_bound(ar.begin(), ar.end(), pair<int,int>({ar[i].second, ar[i].second})) - ar.begin();
		next[i][0] = ft.getmin(n-idx).second;
	}

	for(int exp = 1; exp < nlog2; exp++)
	for(int i = 0 ; i < n; i++)
		if((next[i][exp] = next[i][exp-1]) < n) next[i][exp] = next[next[i][exp-1]][exp-1];

	while(q--){
		int a, b; cin >> a >> b;
		int idx = lower_bound(ar.begin(), ar.end(), pair<int,int>({a, a})) - ar.begin();

		idx = ft.getmin(n-idx).second;
		if(idx == n || ar[idx].second > b){
			cout << 0 << endl;
			continue;
		}

		int ans = 1;
		for(int exp = nlog2-1; exp >= 0; exp--){
			int movie = next[idx][exp]; 
			if(movie == n || ar[movie].second > b) continue;
			ans += 1<<exp;
			idx = movie;
		}
		cout << ans << '\n';
	}
	return 0;
}

