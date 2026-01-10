// Code by $%U%$ $%Y%$
#include <iostream>
#include <set>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q; 
	cin >> n;
	cin >> q;

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	set<int> used(a.begin(), a.end());
	used.insert((int)1e9+1);

	unordered_map<int, int> m;
	int p = 0;
	for(const int &v: used)
		m[v] = p++;

	vector<vector<pair<pair<int, int>, int>>> questions(n+1);
	vector<array<int, 6>> queries(q);

	for(auto &[a, b, c, d, ai, bi]: queries){
		cin >> a >> b >> c >> d;
		c = m[*used.lower_bound(c)];
		d = m[*used.upper_bound(d)]-1;
		ai = questions[a-1].size();
		bi = questions[b].size();
		questions[a-1].push_back({{c, d}, -1});
		questions[b].push_back({{c, d}, -1});
	}

	FenwickTree ft(p);
	for(int i = 0; i <= n; i++){
		ft.add(m[a[i]], +1);	
		for(auto &[range, ans]: questions[i]){
			const auto &[c, d] = range;
			ans = ft.sum(c, d);
		}
	}

	for(auto &[a, b, c, d, ai, bi]: queries)
		cout << questions[b][bi].second - questions[a-1][ai].second << '\n';

	return 0;
}
