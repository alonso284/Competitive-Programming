// Code by $%U%$ $%Y%$
#include <iostream>
#include <cassert>
#include <complex>
#include <bitset>
#include <array>
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

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ask(int y){
	cout << '?' << ' ' << y << endl;
	string ans; cin >> ans;
	return ans == "NO";
}

void guess(int x){
	cout << '!' << ' ' << x << endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int l = 0, r = 1000000000;
	while(l < r){
		int m = (l+r)/2;
		if(ask(m)) r = m;
		else l = m+1;
	}
	guess(l);
}
