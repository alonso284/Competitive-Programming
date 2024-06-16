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
const int MAXN = 5000+5;
const int p = 31;
const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
	map<int, long long> dp;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}



int main(){
	IOS;

	string s;
	cin >> s;

	int n; cin >> n;
	while(n--){
		string t; cin >> t;
		add_string(t);
	}

	vector<long long> dp(s.size()+1, 0);
	dp.back()=1;
	for(int i = s.size()-1; i >= 0; i--){
		int v = 0;
		for(int j = i; j < s.size(); j++){
			v = trie[v].next[s[j]-'a'];
			if(v==-1) break;
			if(trie[v].output){
				dp[i] += dp[j+1];
				dp[i] %= MOD;
			}
		}
	}

	cout << dp[0];

	return 0;
}
