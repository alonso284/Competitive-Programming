// Code by $%U%$ $%Y%$
#include <iostream>
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

void solve();

int main(){
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(int &it: a)
		cin >> it;

	multiset<int> ms;
	for(int i = 0; i < k-1; i++)
		ms.insert(a[i]);

	for(int i = k-1; i < n; i++){
		ms.insert(a[i]);
		int64_t low = *ms.begin();
		cout << low * k << ' ';
		ms.erase(ms.find(a[i-k+1]));
	}
	cout << endl;
}
