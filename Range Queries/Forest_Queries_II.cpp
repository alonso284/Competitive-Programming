// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1739

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <functional>
#include <random>
#include <cstring>
#include <climits>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MOD = 1e9+7;
const int INF = INT_MAX;

struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

	FenwickTree2D(vector<string> &a) {
		n = a.size() + 1;
		m = a[0].size() + 1;
		bit.assign(n, vector<int>(m, 0));
		for (int i = 1; i <= n-1; i++)
			for (int j = 1; j <= m-1; j++)
				add(i, j, a[i-1][j-1] == '*');
	}

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

	int sum(int x1, int y1, int x2, int y2){
		return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
	}

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

int main(){
	IOS;
	int n, q;

	cin >> n >> q;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	FenwickTree2D ft(a);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			if (a[x-1][y-1] == '*') {
				ft.add(x, y, -1);
				a[x-1][y-1] = '.';
			} else {
				ft.add(x, y, 1);
				a[x-1][y-1] = '*';
			}
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 > x2) swap(x1, x2);
			if(y1 > y2) swap(y1, y2);
			cout << ft.sum(x1, y1, x2, y2) << '\n';
		}
	}
	return 0;
}


