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

int main(){
	int n; cin >> n;
	int k; cin >> k;
	int64_t x, a, b, c;
	cin >> x >> a >> b >> c;

	deque<int64_t> dq;
	int64_t sum = 0;
	for(int i = 1; i <= k; i++){
		dq.push_back(x);
		sum += x;
		x = (a*x+b)%c;
	}
	int64_t ans = sum;

	for(int i = k+1; i <= n; i++){
		sum -= dq.front();
		dq.pop_front();

		dq.push_back(x);
		sum += x;

		ans ^= sum;
		x = (a*x+b)%c;
	}

	cout << ans << endl;
}
