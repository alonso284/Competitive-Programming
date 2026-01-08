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
	cin >> tt;
	while(tt--)
		solve();

	return 0;
}

void solve(){
	int n; cin >> n;
	int a, b; cin >> a >> b;

	if(a == 0 || b == 0){
		if(a+b) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for(int c = 1; c <= n; c++)
				cout << c << ' ';
			cout << endl;
			for(int c = 1; c <= n; c++)
				cout << c << ' ';
			cout << endl;
		}
		return;
	}

	int shift = abs(a-b);
	int pairs = min(a, b) - bool(shift);
	if(shift+2*bool(shift) + pairs*2 > n){
		cout << "NO" << endl;
		return;
	}

	vector<int> def(n);
	for(int i = 0; i < n; i++)
		def[i] = i+1;

	vector<int> a_res = def, b_res = def;

	if(shift){
		vector<int> &change = (a<b ? a_res : b_res);
		change.front() = shift+2;
		for(int i = 1; i < shift+2; i++)
			change[i] = i;
	}

	for(int i = shift+2*bool(shift); pairs--; i += 2)
		swap(a_res[i], a_res[i+1]);

	cout << "YES" << endl;
	for(const int it: a_res) cout << it <<  ' ';
	cout << endl;
	for(const int it: b_res) cout << it <<  ' ';
	cout << endl;
}
