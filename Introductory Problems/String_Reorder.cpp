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
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

void solve();

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

void solve(){
	string s; cin >> s;

	map<char, int> freq;
	for(const char &c: s) freq[c]++;

	for(const auto &[c,f]: freq)
		if(f > (s.size()+1)/2){
			cout << -1 << endl;
			return;
		}

	int n = s.size();
	char last = '~';
	while(n--){
		char next = '~';
		for(auto &[c,f]: freq)
			if(f && c != last && c < next || f > (n+1)/2)
				next = c;
		freq[next]--;
		last = next;
		cout << next;
	}
}
