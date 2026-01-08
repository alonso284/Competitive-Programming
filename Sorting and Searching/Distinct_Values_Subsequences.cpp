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
	solve();
	return 0;
}

void solve(){
	int n; cin >> n;

	map<int,int> freq;
	while(n--){
		int it; cin >> it;
		freq[it]++;
	}

	int64_t ans = 1;
	for(const auto &[it, f]: freq)
		ans *= f+1, ans %= 1000000007;

	cout << ans-1 << endl;

}
