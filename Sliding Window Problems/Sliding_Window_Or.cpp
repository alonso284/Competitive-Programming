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

int preffix[10000007], suffix[10000007];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    int front = (int)x;
    for (int i = 0; i < n; i++) {
		preffix[i] = suffix[i] = x;
		x = (a * x + b) % c;
    }

	for(int i = 0; i < n; i += k){
		int limit = min(i+k, n);
		for(int j = 1; j+i < limit; j++){
			preffix[i+j] |= preffix[i+j-1];	
			suffix[limit-j] |= suffix[limit-j+1];	
		}
	}

	int res = 0;
	for(int l = 0, r = k-1; r < n; l++, r++)
		res ^= preffix[r] | suffix[l];

    cout << res << '\n';
    return 0;
}
