// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1653

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

int main(){
	IOS;

	int n, x; cin >> n >> x;

	vi w(n);
	REP(i, n) cin >> w[i];

	// elevators used, capacity used in last elevator
	vpii dp(1<<n, {n+1, 0});	
	dp[0] = {1, 0};
	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1<<j)){
				auto [e, c] = dp[i ^ (1<<j)];
				if(c + w[j] > x) e++, c = w[j];
				else c += w[j];
				dp[i] = min(dp[i], {e, c});
			}
		}
	}

	cout << dp[(1<<n)-1].first << endl;


	return 0;
}
