// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1737

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

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<string> vs;
typedef vector<char> vc;

const int MOD = 1e9+7;
const int INF = INT_MAX;
const int MAXN = 2e5+5;
ll t[MAXN];

struct Vertex {
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(t[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

ll get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(t[pos]);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

Vertex* copy(Vertex* v) {
	if (!v)
		return nullptr;
	return new Vertex(copy(v->l), copy(v->r));
}

int main(){
	IOS;
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> t[i];
	map<int, Vertex*> versions = {{1, build(1, n)}};

	while(q--){
		int cmd, k; cin >> cmd >> k;
		int a, b, x;
		switch(cmd){
			case 1:
				// set value of a-th element to x in k-th version
				cin >> a >> x;
				t[a] = x;
				versions[k] = update(versions[k], 1, n, a);
				break;
			case 2:
				// get sum of elements from a to b in k-th version
				cin >> a >> b;
				cout << get_sum(versions[k], 1, n, a, b) << endl;
				break;
			case 3:
				// create a copy of k-th version
				versions[versions.size()+1] = versions[k];
				break;
		}
	}
	return 0;
}
