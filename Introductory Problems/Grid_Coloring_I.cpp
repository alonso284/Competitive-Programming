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
	int n; cin >> n;
	int m; cin >> m;

	for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
		char c; cin >> c;
		char p = ((i+j)%2 ? 'A': 'B');
		if(p == c) p = (p == 'A' ? 'C': 'D');
		cout << p;
	} cout << endl; }
}
