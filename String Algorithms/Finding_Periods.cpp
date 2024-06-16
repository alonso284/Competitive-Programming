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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
	IOS;

	string s; cin >> s;
	vector<int> pi = z_function(s);

	const int size = s.size();
	for(int i = 0; i < pi.size(); i++){
		if(pi[i]+i == size) cout << i << ' ';
	}
	cout << size;

	return 0;
}
