// Alonso Huerta Escalante
// Link https://cses.fi/problemset/result/8865323/

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
ll x[MAXN];
int n, m;
struct node {
	ll prefix, sub, suffix, sum;
	node(ll prefix, ll sub, ll suffix, ll sum): prefix(prefix), sub(sub), suffix(suffix), sum(sum){}
	node(){}
} st[4*MAXN];

void build(int v, int l, int r){
	if(l == r){
		ll res = max(0LL, x[l]); 
		st[v] = node(res, res, res, x[l]);
	}
	else {
		int m = (l+r)/2;
		build(v<<1, l, m);
		build(v<<1|1, m+1, r);
		st[v].sub = max(max(st[v<<1].sub, st[v<<1|1].sub),
					st[v<<1].suffix + st[v<<1|1].prefix);
		st[v].sum = st[v<<1].sum + st[v<<1|1].sum;
		st[v].prefix = max(st[v<<1].prefix, st[v<<1].sum + st[v<<1|1].prefix);
		st[v].suffix = max(st[v<<1|1].suffix, st[v<<1].suffix + st[v<<1|1].sum);
	}
}

void update(int v, int l, int r, int indx){
	if(l == r){
		ll res = max(0LL, x[l]); 
		st[v] = node(res, res, res, x[l]);
	}
	else {
		int m = (l+r)/2;
		if(indx <= m) update(v<<1, l, m, indx);
		else update(v<<1|1, m+1, r, indx);
		st[v].sub = max(max(st[v<<1].sub, st[v<<1|1].sub),
					st[v<<1].suffix + st[v<<1|1].prefix);
		st[v].sum = st[v<<1].sum + st[v<<1|1].sum;
		st[v].prefix = max(st[v<<1].prefix, st[v<<1].sum + st[v<<1|1].prefix);
		st[v].suffix = max(st[v<<1|1].suffix, st[v<<1].suffix + st[v<<1|1].sum);
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> x[i];

	build(1, 0, n-1);

	while(m--){
		int k, u;
		cin >> k >> u;
		x[--k] = u;
		update(1, 0, n-1, k);
		cout << st[1].sub << endl;

	}


	return 0;

}
