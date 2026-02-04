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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int q; cin >> q;
	
	vector<vector<int>> t(32, vector<int>(n));
	for(int v = 0; v < n; v++)
		cin >> t[0][v], t[0][v]--;

	for(int b = 1; b < 32; b++)
		for(int v = 0; v < n; v++)
		t[b][v] = t[b-1][t[b-1][v]];

	while(q--){
		int x; cin >> x; x--;
		int64_t k; cin >> k;

		for(int b = 0; k; b++, k/=2)
			if(k&1) x = t[b][x];

		cout << x+1 << '\n';
	}
}
