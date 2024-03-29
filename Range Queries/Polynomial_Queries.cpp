#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const bool DEBUG = false;
int n, q;
vector<ll> t;
vector<ll> st;
// cada nodo tiene un par
// el primer numero indica la cantidad de veces de veces que se le debe agreagr algo
// el segundo indica cuantas veces se le agrego
// al momento de actualizar
vector<pair<ll, ll>> lazy;

int MAXN = 0;

ll gauss(ll n){
	return n * (n+1) / 2;
}

void push(int v, int l, int r){
	int m = (l+r)/2;

	ll rep = lazy[v].second;
	ll inif = lazy[v].first;
	ll lenf = m - l + 1;
	ll inis = lenf*rep + inif;
	ll lens = r - (m+1) + 1;

	if(DEBUG) cout << "push " << " v: " << v << " l: " << l << " r: " << r << " inif: " << inif << " inis: " << inis << " lenf: " << lenf << " lens: " << lens << " rep: " << rep << endl;

	lazy[v<<1].first += inif;
	lazy[v<<1].second += rep;
	st[v<<1] += (inif * lenf) + (rep * gauss(lenf));

	lazy[v<<1|1].first += inis;
	lazy[v<<1|1].second += rep;
	st[v<<1|1] += (inis * lens) + (rep * gauss(lens));
	
	lazy[v] = {0, 0};
}

void build(int v, int l, int r){
	MAXN = max(MAXN, v);
	if(l == r)
		st[v] = t[l];
	else{
		int m = (l+r)/2;
		build(v<<1, l, m);
		build(v<<1|1, m+1, r);
		st[v] = st[v<<1] + st[(v<<1)|1];
	}
	if(DEBUG) cout << "st[" << v << "]: " << st[v] << " l " << l << " r " << r << endl;
}

void update(int v, int l, int r, int ql, int qr, int ini){
	if(DEBUG) cout << "update " << " v: " << v << " l: " << l << " r: " << r << " ql: " << ql << " qr: " << qr << " ini: " << ini << endl;
	if(ql > qr){
		if(DEBUG) cout << "quitting" << endl;
		return;
	}
	if(ql == l && qr == r){
		if(DEBUG) cout << "updating" << endl;
		lazy[v].first += ini;
		lazy[v].second++;
		st[v] += (ll)ini * (r-l+1) + gauss(r-l+1);
	} else {
		push(v, l, r);
		int m = (l+r)/2;
		update(v<<1, l, m, ql, min(m, qr), ini);
		update(v<<1|1, m+1, r, max(m+1, ql), qr, ini + max(0, m - ql + 1));
		st[v] = st[v<<1] + st[v<<1|1];
	}
}

ll query(int v, int l, int r, int ql, int qr){
	if(DEBUG) cout << "query " << " v: " << v << " l: " << l << " r: " << r << " ql: " << ql << " qr: " << qr << endl;
	if(ql > qr){
		if(DEBUG) cout << "quitting" << endl;
		return 0;
	}
	if(ql == l && qr == r){
		if(DEBUG) cout << "updating" << endl;
		return st[v];
	} else {
		push(v, l, r);
		int m = (l+r)/2;
		return query(v<<1, l, m, ql, min(m, qr)) + query(v<<1|1, m+1, r, max(m+1, ql), qr);
	}
}

void print(){
	for(int i = 1; i <= MAXN; i++){
		cout << "st[" << i << "]: " << st[i] << " ";
		cout << "lazy[" << i << "]: " << lazy[i].first << " " << lazy[i].second << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){
	cin >> n >> q;
	st.resize(4*n);
	lazy.resize(4*n);
	t.resize(n);
	for(int i = 0; i < n; i++) cin >> t[i];
	build(1, 0, n-1);

	while(q--){
		int cmd, l, r;
		cin >> cmd >> l >> r;
		l--; r--;
		switch(cmd){
			case 1:
				update(1, 0, n-1, l, r, 0);
				break;
			case 2:
				cout << query(1, 0, n-1, l, r) << endl;
				break;
			default:
				cerr << "Invalid input" << endl;
				return 1;
		}
		if(DEBUG) print();
	}
	return 0;
}
