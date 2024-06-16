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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vvi aut;
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'A' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('A' + c == s[i]);
        }
    }
}

int n;
string m;
long long dp[1005][105];
bool vis[1005][105];
long long pot[1005];
long long DP(int i, int j){
	if(j == m.size()) return pot[n-i];
	if(i == n) return 0;

	if(vis[i][j]) return dp[i][j];
	vis[i][j] = true;

	
	for(int c = 0; c < 26; c++){
		int next = aut[j][c];
		dp[i][j] += DP(i+1, next);
	}
	dp[i][j] %= MOD;
	return dp[i][j];
}

int main(){
	IOS;

	pot[0] = 1;
	FOR(i, 1, 1005) pot[i] = (pot[i-1]*26)%MOD;

	cin >> n >> m;
	compute_automaton(m, aut);
	cout << DP(0, 0) << endl;

	return 0;
}
