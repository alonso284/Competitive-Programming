// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/2166

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
pair<ll, ll> st[4*MAXN];
ll x[MAXN];
int n, q;

void build(int v, int l, int r){
	if(l == r){
		st[v].first = x[l];
		st[v].second = max(0LL, x[l]);
	}
	else {
		int m = (l+r)/2;
		build(v<<1, l, m);
		build(v<<1|1, m+1, r);
		st[v].first = st[v<<1].first + st[v<<1|1].first;
		st[v].second = max(st[v<<1].second, st[v<<1].first + st[v<<1|1].second);
	}
}

void update(int v, int l, int r, int indx){
	if(l == r){
		st[v].first = x[l];
		st[v].second = max(0LL, x[l]);
	}
	else {
		int m = (l+r)/2;
		if(indx <= m) update(v<<1, l, m, indx);
		else update(v<<1|1, m+1, r, indx);
		st[v].first = st[v<<1].first + st[v<<1|1].first;
		st[v].second = max(st[v<<1].second, st[v<<1].first + st[v<<1|1].second);
	}
}

pair<ll, ll> query(int v, int l, int r, int ql, int qr){
	if(ql > qr) return {0, 0};
	if(ql <= l && r <= qr) return st[v];
	int m = (l+r)/2;
	pair<ll, ll> left = query(v<<1, l, m, ql, min(qr, m));
	pair<ll, ll> right = query(v<<1|1, m+1, r, max(ql, m+1), qr);
	return {left.first + right.first, max(left.second, left.first + right.second)};
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> x[i];

	build(1, 0, n-1);

	
	while(q--){
		int k, u, a, b;
		int cmd; cin >> cmd;
		switch(cmd){
			case 1:
				cin >> k >> u;
				k--; x[k] = u;
				update(1, 0, n-1, k);
				break;
			case 2:
				cin >> a >> b;
				a--; b--;
				cout << query(1, 0, n-1, a, b).second << endl;
				break;
		}
	}


	return 0;

}
