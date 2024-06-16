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
const int p = 31;
const int MAXN = 1e6+5;
const int k = 26;
vll hashl(MAXN);
vll hashr(MAXN);
vll pot(MAXN);
string s;

// check if s[pivot-length, pivot+length] is a palindrome
bool odd_palindrome(int pivot, int length){
	if(pivot-length < 0 || pivot+length >= s.size()) return false;


	ll h1 = hashl[pivot];
	if(pivot-length) h1 -= hashl[pivot-length-1];
	// distance of pivot+length to the end of the string
	h1 *= pot[s.size()-1-(pivot+length)];
	h1 %= MOD;
	if(h1 < 0) h1 += MOD;

	ll h2 = hashr[pivot];
	if(pivot+length < s.size()-1) h2 -= hashr[pivot+length+1];
	// distance of pivot-length to the beginning of the string
	h2 *= pot[pivot-length];
	h2 %= MOD;
	if(h2 < 0) h2 += MOD;
	
	return h1 == h2;
}

bool even_palindrome(int pivot, int length){
	if(pivot-length < 0 || pivot+length+1 >= s.size()) return false;

	ll h1 = hashl[pivot];
	if(pivot-length) h1 -= hashl[pivot-length-1];
	// distance of pivot+length+1 to the end of the string
	h1 *= pot[s.size()-1-(pivot+length+1)];
	h1 %= MOD;
	if(h1 < 0) h1 += MOD;

	ll h2 = hashr[pivot+1];
	if(pivot+length+1 < s.size()-1) h2 -= hashr[pivot+length+2];
	// distance of pivot-length to the beginning of the string
	h2 *= pot[pivot-length];
	h2 %= MOD;
	if(h2 < 0) h2 += MOD;

	return h1 == h2;
}


int main(){

	IOS;
	cin >> s;

	pot[0] = 1;
	for(int i = 1; i < MAXN; i++) pot[i] = (pot[i-1]*p)%MOD;

	for(int i = 0; i < s.size(); i++){
		hashl[i] = (s[i]-'a'+1)*pot[i];
		if(i) hashl[i] += hashl[i-1];
		hashl[i] %= MOD;
	}

	for(int i = s.size()-1; i >= 0; i--){
		hashr[i] = (s[i]-'a'+1)*pot[s.size()-1-i];
		if(i < s.size()-1) hashr[i] += hashr[i+1];
		hashr[i] %= MOD;
	}

	int indx = -1;
	int length = -1;
	for(int i = 0; i < s.size(); i++){
		int ini = 0, fin = s.size()-1;
		while(ini < fin){
			int mid = (ini+fin+1)/2;
			if(odd_palindrome(i, mid)) ini = mid;
			else fin = mid-1;
		}
		if(2*ini+1 > length){
			length = 2*ini+1;
			indx = i;
		}
	}

	for(int i = 0; i < s.size()-1; i++){
		int ini = 0, fin = s.size()-1;
		if(s[i] != s[i+1]) continue;
		while(ini < fin){
			int mid = (ini+fin+1)/2;
			if(even_palindrome(i, mid)) ini = mid;
			else fin = mid-1;
		}
		if(2*ini+2 > length){
			length = 2*ini+2;
			indx = i;
		}
	}

	if(length%2){
		for(int i = indx-length/2; i <= indx+length/2; i++) cout << s[i];
		cout << endl;
	}else{
		for(int i = indx-length/2+1; i <= indx+length/2; i++) cout << s[i];
		cout << endl;
	}

	return 0;
}

