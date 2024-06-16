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
 
const int K = 26;
 
struct Vertex {
    int next[K];
	bool present = false;
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
 
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};
 
vector<Vertex> t(1);
 
int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
	return v;
}
 
int go(int v, char ch);
 
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
 
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
 
int main(){
	IOS;
 
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<int> ans;
	while(n--){
		string p;
		cin >> p;
		ans.push_back(add_string(p));
	}
	
	int v = 0;
	for(int i = 0; i < s.size(); i++){
		v = go(v, s[i]);
		t[v].present = true;
	}
 
	queue<int> q;
	stack<int> st;
 
	q.push(0);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		st.push(v);
 
		for(int i = 0; i < K; i++)
			if(t[v].next[i] != -1)
				q.push(t[v].next[i]);
	}
 
	while(!st.empty()){
		int v = st.top();
		st.pop();
 
		if(t[v].present)
			t[get_link(v)].present = true;
	}
 
	for(int i = 0 ; i < ans.size(); i++)
		cout << (t[ans[i]].present? "YES": "NO") << endl;
 
 
	return 0;
}