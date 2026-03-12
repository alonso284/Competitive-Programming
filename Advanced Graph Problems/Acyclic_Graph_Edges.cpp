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
	int m; cin >> m;

	while(m--){
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		cout << a << ' ' << b << endl;
	}
}
