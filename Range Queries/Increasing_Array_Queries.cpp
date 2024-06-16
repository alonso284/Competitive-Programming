// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/2416

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a) for(int i = 0; i < a; i++)
#define RREP(i, a) for(int i = a-1; i >= 0; i--)
#define FORIT(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define FORITR(it, a) for(auto it = a.rbegin(); it != a.rend(); it++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MOD = 1e9+7;
const int INF = INT_MAX;
const int MAXN = 2e5 + 5;

int n, q;
ll x[MAXN], st[20][MAXN], prefix[20][MAXN], xp[MAXN];


int main(){
	IOS;
	cin >> n >> q;
	REP(i, n) cin >> x[i];
	REP(i, n){
		st[0][i] = x[i];
		xp[i] = x[i] + (i ? xp[i-1] : 0);
	}

	int logn = log2(n) + 1;
	for(int i = 1; i <= logn; i++){
		for(int j = 0; j <= n; j += (1<<i)){
			ll last = x[j];
			st[i][j] = x[j];
			for(int k = j+1; k < j + (1<<i) && k < n; k++){
				if(x[k] >= last){
					last = x[k];
				} else {
					prefix[i][k] = last - x[k];
				}
				prefix[i][k] += prefix[i][k-1];
				st[i][k] = last;
			}
		}
	}


	while(q--){
		int a, b;
		cin >> a >> b;
		a--; b--;
		ll ans = 0;
		ll last = x[a];

		while(a <= b){
			int bit = (a & -a);

			if(!bit) bit = logn;
			else bit = log2(bit);

			int limit = min(a + (1<<bit) - 1, b);

			// look for the lower bound of `last' inside st[bit][a] and st[bit][a + (1<<bit) - 1]
			int it = lower_bound(st[bit] + a, st[bit] + limit + 1, last) - st[bit];

			// add prefix up to limit
			ans += prefix[bit][limit];

			// level all items from a to it to last
			if(it != a)
				ans += (it - a)*last - prefix[bit][it-1] - xp[it-1] + (a ? xp[a-1] : 0);

			last = max(last, st[bit][limit]);

			a = limit + 1;
		}
		cout << ans << '\n';

	}

	return 0;
}
