// Code by $%U%$ $%Y%$
#include <iostream>
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

const int p = 31;
const int m = 1e9 + 9;

int64_t p_pow(int exp){
	static vector<int64_t> power = {1};
	while(exp >= power.size()) power.push_back((power.back() * p) % m);
	return power[exp];
}

vector<int64_t> compute_hash(string const& s) {
	const int n = s.size();
	vector<int64_t> hash(n);
    long long hash_value = 0;
	for(int i = 0; i < n; i++){
		char c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow(i)) % m;
		hash[i] = hash_value;
    }
    return hash;
}

bool palindrome(const vector<int64_t> &fh, const vector<int64_t> &rh, const int center, const int length, const bool even){
	const int n = fh.size();

	int l = center-length;
	int r = center+length+even;

	if(l < 0 || n <= r) return false;

	int64_t fhv = (fh[r]-(l>0  ?fh[l-1]:0)) * p_pow(n-1-r);
	int64_t rhv = (rh[l]-(r<n-1?rh[r+1]:0)) * p_pow(l);

	fhv %= m; if(fhv < 0) fhv += m;
	rhv %= m; if(rhv < 0) rhv += m;

	return fhv == rhv;
}

int main(){
	string s; cin >> s;
	const int n = s.size();
	vector<int64_t> fh = compute_hash(s);
	reverse(s.begin(), s.end());
	vector<int64_t> rh = compute_hash(s);
	reverse(s.begin(), s.end());
	reverse(rh.begin(), rh.end());

	// for(const int64_t &it: fh) clog << it << ' ';
	// clog << endl;
	// for(const int64_t &it: rh) clog << it << ' ';
	// clog << endl;

	vector<int> dp(n);
	for(int i = 0; i < n; i++){
		int l, r;

		// odd size
		l = 0, r = n;
		while(l < r){
			int mit = (l+r+1)/2;
			if(palindrome(fh, rh, i, mit, false)) l = mit;
			else r = mit-1;
		}
		dp[i+l] = max(dp[i+l], 2*l+1);

		// even size
		l = 0, r = n;
		while(l < r){
			int mit = (l+r+1)/2;
			if(palindrome(fh, rh, i, mit, true)) l = mit;
			else r = mit-1;
		}
		if(l > 0 || (i < n-1 && s[i] == s[i+1]))
			dp[i+1+l] = max(dp[i+1+l], 2*l+2);
	}

	for(int i = n-2; i >= 0; i--) dp[i] = max(dp[i+1]-2, dp[i]);

	for(const int64_t &it: dp) cout << it << ' ';
	cout << endl;

	return 0;
}
