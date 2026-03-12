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

map<int, int> compress;

void compress_array(const vector<int> &a){
	set<int> s(a.begin(), a.end());
	int val = 1;
	for(const int &it: s) compress[it] = val++;
}

struct FenwickTree {
    vector<int64_t> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int64_t sum(int r) {
        int64_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int64_t sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int64_t delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} ft(200005);

int64_t ans = 0;

void add(int x){
	ft.add(compress[x], +1);
	ans += ft.sum(compress[x], 200004) - ft.sum(compress[x], compress[x]);
}

void remove(int x){
	ft.add(compress[x], -1);
	ans -= ft.sum(0, compress[x]) - ft.sum(compress[x], compress[x]);
}

int64_t value(){
	return ans;
}

int main(){
	int n; cin >> n;
	int k; cin >> k;

	vector<int> a(n);
	for(int &it: a) cin >> it;
	compress_array(a);

	for(int i = 0; i < k-1; i++)
		add(a[i]);

	for(int i = k-1; i < n; i++){
		add(a[i]);
		cout << value() << ' ';
		remove(a[i-k+1]);
	}

	cout << endl;
	return 0;
}
