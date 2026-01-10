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

#define MAXN 200000
struct Node {
	int64_t pre, best, suf, sum;

	Node() {
		pre = suf = best = sum = 0;
	}
} t[4*MAXN];

void build(const vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v].pre = t[v].suf = t[v].best = max(a[tl], 0), t[v].sum = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);


		t[v].pre = max(t[v*2].pre, t[v*2].sum+t[v*2+1].pre);
		t[v].suf = max(t[v*2].suf+t[v*2+1].sum, t[v*2+1].suf);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;
		t[v].best = max({ t[v*2].best,
                 t[v*2+1].best,
                 t[v*2].suf + t[v*2+1].pre });
    }
}

Node sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return Node();
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    Node ln = sum(v*2, tl, tm, l, min(r, tm));
    Node rn = sum(v*2+1, tm+1, tr, max(l, tm+1), r);

	Node n;
	n.pre = max(ln.pre, ln.sum+rn.pre);
	n.suf = max(ln.suf+rn.sum, rn.suf);
	n.sum = ln.sum + rn.sum;
	n.best = max({ ln.best,
			 rn.best,
			 ln.suf + rn.pre });
	return n;
}

int main(){
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n);
	for(int &it: a)
		cin >> it;

	build(a, 1, 0, n-1);
	while(q--){
		int a, b; cin >> a >> b; a--, b--;
		cout << sum(1, 0, n-1, a, b).best << endl;
	}

	build(a, 1, 0, n-1);
}
