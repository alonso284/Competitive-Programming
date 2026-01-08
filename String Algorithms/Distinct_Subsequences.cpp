// Code by $%U%$ $%Y%$
#include <iostream>
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

array<int,26> freq;
const int m = 1000000007;

int main(){
	string s; cin >> s;
	const int n = s.size();
	vector<int64_t> dp(n);
	int64_t sum = 0;
	for(int i = n-1; i >= 0; i--)
		dp[i] = sum+1 - freq[s[i]-'a'], dp[i] %= m, freq[s[i]-'a'] += dp[i], freq[s[i]-'a'] %= m, sum += dp[i], sum %= m;

	if(sum < 0) sum += m;
	cout << sum << endl;

	return 0;
}
