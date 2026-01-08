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

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

	vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

#define MAXN 100005
int t[MAXN*4];

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

int min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(min(v*2, tl, tm, l, min(r, tm)),
          	min(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int64_t st[MAXN*4], marked[MAXN*4];

void push(int v, int tl, int tr) {
    if (marked[v]) {
		int tm = (tl + tr) / 2;
        st[v*2] +=    int64_t(tm-tl+1)     * marked[v];
        st[v*2+1] +=  int64_t(tr-(tm+1)+1) * marked[v];
        marked[v*2] += marked[v];
        marked[v*2+1] += marked[v];
        marked[v] = 0;
    }
}

void add(int v, int tl, int tr, int l, int r, int64_t delta) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        st[v] += delta*(tr-tl+1);
        marked[v] += delta;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        add(v*2, tl, tm, l, min(r, tm), delta);
        add(v*2+1, tm+1, tr, max(l, tm+1), r, delta);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return st[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

int main(){
	string s; cin >> s;
	s.push_back('$');
	const int64_t n = s.size();

	vector<int> sa = sort_cyclic_shifts(s);
	vector<int> pos(n); for(int i = 0; i < n; i++) pos[sa[i]] = i;
	vector<int> lcp(n);
	for (int i = 0, k = 0; i < n; i++)
	if (pos[i] != n - 1) {
		int j = sa[pos[i] + 1];
		while (s[i + k] == s[j + k])
			k++;
		lcp[pos[i]] = k;
		if (k)
			k--;
	}

	int64_t k; cin >> k;
	build(lcp, 1, 0, n-1);

	// for(const int &it: sa) cout << it << ' '; cout << endl;
	// for(const int &it: pos) cout << it << ' '; cout << endl;
	// for(const int &it: lcp) cout << it << ' '; cout << endl;
	// for(const int &it: sa) cout << s.substr(it, n-it) << endl;

	int idx = 1;
	while(k){
		int len = get(1, 0, n-1, idx)+1;

		int l = 0, r = n-1-idx;
		while(l < r){
			int mit = (l+r+1)/2;
			int nidx = idx+mit;
			int rlcp = min(1, 0, n-1, idx, nidx-1);
			if(rlcp >= len) l = mit;
			else r = mit-1;
		}

		if(k - (l+1) <= 0){
			cout << s.substr(sa[idx], len);
			return 0;
		}

		// Optimization
		int clcp = (l ?  min(1, 0, n-1, idx, idx+l-1) : n-1-sa[idx]);
		// cout << "FROM THE RANGE FOUND " << idx << ' ' << idx+l << " LCP " << clcp << endl;
		// cout << "YOU CAN FORWARD UP TO " << (clcp-len+1)*(l+1)  << " BY " << l+1 << endl;
		int64_t MIN = 1, MAX = (clcp-len+1);
		// what is biggest skip (MIN <= `skip` <= MAX) such that skip * l < k
		int skip = max(MIN, min((k-1)/(l+1), MAX));
		k -= int64_t(l+1)*skip;
		// cout << "SKIPPING " << skip << ' ' << l+1 << ' ' << k << endl;

		add(1, 0, n-1, idx, idx+l, skip);
		// for(int i = 1; i < n; i++) cout << get(1, 0, n-1, i) << ' ';
		// cout << endl;
		while(get(1, 0, n-1, idx) == n-1-sa[idx]) idx++;
	}

	return 0;
}
