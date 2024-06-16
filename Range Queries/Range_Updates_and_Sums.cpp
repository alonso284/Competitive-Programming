// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1735

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <functional>
#include <random>
#include <cstring>
#include <climits>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;
const int MOD = 1e9+7;
const int INF = INT_MAX;
const int MAXN = 200005;
ll a[MAXN];

ll t[4*MAXN];
// false = increase, true = add
pair<bool, ll> marked[4*MAXN];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
		marked[v] = {true, 0};
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
    }
}

void push(int v, int l, int r) {
	// if the command is add, and you add nothing, then do nothing
	if(marked[v].first && !marked[v].second) return;

	int m = (l+r)/2;
	int left_size = m-l+1;
	int right_size = r-m;
	if(marked[v].first){
		marked[v*2].second += marked[v].second;
		marked[v*2+1].second += marked[v].second;
		t[v*2] += marked[v].second*left_size;
		t[v*2+1] += marked[v].second*right_size;
	}
	else {
		marked[v*2] = marked[v];
		marked[v*2+1] = marked[v];
		t[v*2] = marked[v].second*left_size;
		t[v*2+1] = marked[v].second*right_size;
	}
	marked[v] = {true, 0};
}

void update(int v, int tl, int tr, int l, int r, bool cmd, ll x) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
		if(cmd){
			marked[v].second += x;
			t[v] += x*(tr-tl+1);
		}
		else {
			marked[v] = {cmd, x};
			t[v] = x*(tr-tl+1);
		}
	} else {
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		update(v*2, tl, tm, l, min(r, tm), cmd, x);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, cmd, x);
		t[v] = t[v*2] + t[v*2+1];
    }
}

ll get(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l <= tl && tr <= r)
		return t[v];
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	return get(v*2, tl, tm, l, min(r, tm))
		   + get(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main(){
	IOS;

	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(a, 1, 0, n-1);
	while(q--){
		int cmd; cin >> cmd;
		int a, b, x;
		switch(cmd){
			case 1:
				cin >> a >> b >> x;
				update(1, 0, n-1, a-1, b-1, true, x);
				break;
			case 2:
				cin >> a >> b >> x;
				update(1, 0, n-1, a-1, b-1, false, x);
				break;
			case 3:
				cin >> a >> b;
				cout << get(1, 0, n-1, a-1, b-1) << endl;
				break;
		}
	}

	return 0;
}


