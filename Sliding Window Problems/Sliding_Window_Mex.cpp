// Code by $%U%$ $%Y%$
#include <iostream>
#include <complex>
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

#define MAXN 200005

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} ft(MAXN);

int freq[MAXN];

inline void add(int x){
	if(MAXN <= x) return;
	if(!freq[x]) ft.add(x, +1);
	freq[x]++;
}

inline void erase(int x){
	if(MAXN <= x) return;
	freq[x]--;
	if(!freq[x]) ft.add(x, -1);
}

inline int MEX(){
	int l = 0, r = MAXN-1;
	while(l < r){
		int m = (l+r+1)/2;
		if(ft.sum(m) == m+1) l = m;
		else r = m-1;
	}
	return l+ft.sum(0);
}

int main(){
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(int &it: a)
		cin >> it;

	for(int i = 0; i < k-1; i++) add(a[i]);
	for(int i = k-1; i < n; i++){
		add(a[i]);
		cout << MEX() << ' ';
		erase(a[i-k+1]);
	}
	return 0;
}
