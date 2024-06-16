
// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/2206

#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

const int MAXN = 2 * 100005;
const ll INF =(ll) MAXN * INT_MAX;

// sum / max prefix
ll pst[4*MAXN], sst[4*MAXN];
ll x[MAXN];
int n, q;

void build(ll *st, const bool w, int v, int l, int r){
	if(l == r){
		st[v] = x[l] + (w? l+1: n-l);
	}
	else {
		int m = (l+r)/2;
		build(st, w, v<<1, l, m);
		build(st, w, v<<1|1, m+1, r);
		st[v] = min(st[v<<1], st[v<<1|1]);
	}
}

void update(ll *st, const bool w, int v, int l, int r, int indx){
	if(l == r){
		st[v] = x[l] + (w? l+1: n-l);
	}
	else {
		int m = (l+r)/2;
		if(indx <= m) update(st, w, v<<1, l, m, indx);
		else update(st, w, v<<1|1, m+1, r, indx);
		st[v] = min(st[v<<1], st[v<<1|1]);
	}
}

ll query(ll *st, const bool w, int v, int l, int r, int ql, int qr){
	if(ql > qr) return INT_MAX;
	if(ql <= l && r <= qr) return st[v];
	int m = (l+r)/2;
	return min(query(st, w, v<<1, l, m, ql, min(qr, m)), query(st, w, v<<1|1, m+1, r, max(ql, m+1), qr));
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> x[i];

	build(sst, true, 1, 0, n-1);
	build(pst, false, 1, 0, n-1);

	/* for(int i = 0; i < n; i++) cout << query(sst, true, 1, 0, n-1, i, i) << ' '; cout << endl; */
	/* for(int i = 0; i < n; i++) cout << query(pst, false, 1, 0, n-1, i, i) << ' '; cout << endl; */
	
	while(q--){
		int k, u;
		int cmd; cin >> cmd;
		switch(cmd){
			case 1:
				cin >> k >> u;
				k--; x[k] = u;
				update(sst, true, 1, 0, n-1, k);
				update(pst, false, 1, 0, n-1, k);
				break;
			case 2:
				cin >> k;
				k--;
				ll left = query(sst, true, 1, 0, n-1, k, n-1) - (k+1);
				ll right = query(pst, false, 1, 0, n-1, 0, k) - (n-k);
				/* cout << left << ' ' << right << endl; */
				cout << min(left, right) << endl;
				break;
		}
		/* for(int i = 0; i < n; i++) cout << query(sst, true, 1, 0, n-1, i, i) << ' '; cout << endl; */
		/* for(int i = 0; i < n; i++) cout << query(pst, false, 1, 0, n-1, i, i) << ' '; cout << endl; */
	}


	return 0;

}
