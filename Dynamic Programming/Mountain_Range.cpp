// Code by $%U%$ $%Y%$
#include <iostream>
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

void solve();

#define MAXN 200005

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

int t[4*MAXN];

int max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(max(v*2, tl, tm, l, min(r, tm)),
           max(v*2+1, tm+1, tr, max(l, tm+1), r));
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
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void solve(){
	int n; cin >> n;
	vector<int> a(n);

	for(int &it: a)
		cin >> it;

	stack<pair<int,int>> s; 

	vector<pair<int,int>> ord(n);
	for(int i = 0; i < n; i++) ord[i] = {a[i], i};
	sort(ord.begin(), ord.end());

	s = stack<pair<int,int>>();
	s.push({INT_MAX, n});
	vector<int> MAXR(n);
	for(int i = n-1; i >= 0; i--){
		while(s.top().first < a[i]) s.pop();
		MAXR[i] = s.top().second;
		s.push({a[i], i});
	}

	s = stack<pair<int,int>>();
	s.push({INT_MAX, -1});
	vector<int> MAXL(n);
	for(int i = 0; i < n; i++){
		while(s.top().first < a[i]) s.pop();
		MAXL[i] = s.top().second;
		s.push({a[i], i});
	}

	for(const auto &[ai, i]: ord)
		update(1, 0, n-1, i, max(1, 0, n-1, MAXL[i]+1, MAXR[i]-1)+1);

	cout << max(1, 0, n-1, 0, n-1) << endl;




}
