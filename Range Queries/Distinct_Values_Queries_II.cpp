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

#define MAXN 200000
int t[4*MAXN];

void build(const vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int getmin(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(getmin(v*2, tl, tm, l, min(r, tm)), getmin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int q; cin >> q;
	vector<int> ar(n);
	map<int, set<int>> m;
	for(int &it: ar)
		cin >> it, m[it].insert(n);

	vector<int> P(n, n);
	for(int i = n-1; i >= 0; i--){
		if(m[ar[i]].size() == 1) P[i] = n;
		else P[i] = *m[ar[i]].begin();
		m[ar[i]].insert(i);
	}

	build(P, 1, 0, n-1);
	int a, b, k, u;
	while(q--){
		int cmd; cin >> cmd;
		switch(cmd){
			case 2:
				cin >> a >> b; a--, b--;
				cout << (getmin(1, 0, n-1, a, b) > b? "YES": "NO") << '\n';
				continue;
			case 1:
				cin >> k >> u; k--;
				int v = ar[k];
				ar[k] = u;

				set<int> &mv = m[v];
				set<int> &mu = m[u];

				if(k != *mv.begin()){
					auto it = mv.lower_bound(k);
					auto itp = it; itp--;
					auto itn = it; itn++;
					update(1, 0, n-1, *itp, *itn);
				}
				mv.erase(k);

				if(mu.empty())
					mu.insert(n);
				mu.insert(k);
				if(k != *mu.begin()){
					auto it = mu.lower_bound(k);
					auto itp = it; itp--;
					update(1, 0, n-1, *itp, k);
				}
				update(1, 0, n-1, k, *mu.upper_bound(k));

				continue;
		}
	}
}
