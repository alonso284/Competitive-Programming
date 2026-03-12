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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 1; i < k; i++){
		pq.push({x, i});
		x = (a*x+b)%c;
	}

	int ans = 0;
	for(int i = k; i <= n; i++){
		pq.push({x, i});
		while(pq.top().second < i-k+1) pq.pop();

		ans ^= pq.top().first;
		x = (a*x+b)%c;
	}

	cout << ans << endl;
}
