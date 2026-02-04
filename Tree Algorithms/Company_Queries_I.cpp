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

void solve();

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

void solve(){
	int n; cin >> n;
	int q; cin >> q;
	vector<vector<int>> parent(20, vector<int>(n, -1));
	for(int i = 1; i < n; i++)
		cin >> parent[0][i], parent[0][i]--;

	for(int b = 1; b < 20; b++)
	for(int i = 0; i < n; i++)
		if(parent[b-1][i] != -1)
			parent[b][i] = parent[b-1][parent[b-1][i]];

	while(q--){
		int x, k; cin >> x >> k;

		int p = x-1;
		for(int b = 0; k; k /= 2, b++)
			if(k%2 && p != -1)
				p = parent[b][p];

		cout << p + (p >= 0) << endl;
	}
}
