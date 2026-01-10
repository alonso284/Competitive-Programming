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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n);
	for(int &it: a)
		cin >> it;

	vector<pair<pair<int,int>, int>> queries(q);
	for(int i = 0; i < q; i++){
		queries[i].second = i;
		auto &[r, l] = queries[i].first;
		cin >> l >> r; l--, r--;
	}

	sort(queries.begin(), queries.end());

	FenwickTree ft(n);
	vector<int> answers(q);
	stack<pair<int,int>> h;
	h.push({(int)1e9+1, -1});
	int i = 0;

	for(auto &[coor, idx]: queries){
		const auto &[r, l] = coor;
		while(i <= r){
			while(h.top().first < a[i]) h.pop();
			if(h.size() > 1) ft.add(h.top().second, -1);
			h.push({a[i], i});
			i++;
		}

		answers[idx] = (r-l+1) + ft.sum(l, r);
	}

	for(const int &it: answers) cout << it << ' ';
	cout << endl;

	return 0;
}
