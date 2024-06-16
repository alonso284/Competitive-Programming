// Alonso Huerta Escalante
// Link 

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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<string> vs;
typedef vector<char> vc;

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
const int prime = 31;
const int MAXN = 2e5+5;
ll pot[MAXN];

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
			ret += bit[r];
			ret %= MOD;
		}
        return ret;
    }

    ll sum(int l, int r) {
		ll ans = sum(r) - sum(l-1);
		ans %= MOD;
		if(ans < 0) ans += MOD;
		return ans;
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1)){
            bit[idx] += delta;
			bit[idx] %= MOD;
		}
    }
};

int main(){
	IOS;

	pot[0] = 1;
	for(int i = 1; i < MAXN; i++){
		pot[i] = pot[i-1]*prime;
		pot[i] %= MOD;
	}

	int n, m;
	cin >> n >> m;
	FenwickTree ft_ltr(n+1), ft_rtl(n+1);
	
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		ft_ltr.add(i, (s[i-1]-'a'+1)*pot[i-1]);
		ft_rtl.add(i, (s[i-1]-'a'+1)*pot[n+1-i]);
	}

	char x;
	int a, b, k;
	while(m--){
		int cmd; cin >> cmd;
		switch(cmd){
			case 1:
				cin >> k >> x;

				ft_ltr.add(k, -((s[k-1]-'a'+1)*pot[k-1]%MOD));
				ft_rtl.add(k, -((s[k-1]-'a'+1)*pot[n+1-k]%MOD));

				s[k-1] = x;

				ft_ltr.add(k, (s[k-1]-'a'+1)*pot[k-1]%MOD);
				ft_rtl.add(k, (s[k-1]-'a'+1)*pot[n+1-k]%MOD);

				break;
			case 2:
				cin >> a >> b;

				ll h1 = ft_ltr.sum(a, b);
				h1 *= pot[n+1-b];
				h1 %= MOD;

				ll h2 = ft_rtl.sum(a, b);
				h2 *= pot[a-1];
				h2 %= MOD;

				cout << (h1 == h2 ? "YES" : "NO") << endl;
				break;
		}
	}

	return 0;
}
