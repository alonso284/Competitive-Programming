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

#define MAXN 200005
int st[30][30][MAXN];
int64_t sm[MAXN][30];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sm[i][31-__builtin_clz(a[i])] = a[i];
	}

	for(int bit = 0; bit < 30; bit++){
		for(int j = 0; j < n; j++)
			st[bit][0][j] = (bit == 31-__builtin_clz(a[j]) ? a[j]: INT_MAX);

		for (int i = 1; i < 30; i++)
		for (int j = 0; j + (1 << i) <= n; j++)
			st[bit][i][j] = min(st[bit][i - 1][j], st[bit][i - 1][j + (1 << (i - 1))]);
	}

	for(int i = 1; i < n; i++)
		for(int j = 0; j < 30; j++)
			sm[i][j] += sm[i - 1][j];

	while(q--){
		int L, R; cin >> L >> R; L--, R--;
		int64_t ans = 0;

		int i = 31-__builtin_clz(R-L+1);
		for(int bit = 0; bit < 30; bit++){
			int minimum = min(st[bit][i][L], st[bit][i][R - (1 << i) + 1]);
			int64_t sum = sm[R][bit] - (L ? sm[L-1][bit]: 0);
			if((1<<(bit+1))-1 <= ans || (minimum != INT_MAX && ans+1 >= minimum)) ans += sum;
			else break;
		}
		cout << ans+1 << '\n';
	}
	return 0;
}
