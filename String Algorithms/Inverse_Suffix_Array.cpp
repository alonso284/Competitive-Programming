// Code by $%U%$ $%Y%$
#include <iostream>
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
	vector<int> sf(n);
	vector<int> si(n);
	for(int i = 0; i < n; i++)
		cin >> sf[i], sf[i]--, si[sf[i]] = i;
	sf.push_back(n);
	si.push_back(-1);

	char last = 'a';
	string res(n, '#');
	for(int i = 0; i < n; i++){
		if(last > 'z'){
			cout << -1 << endl;
			return 0;
		}
		res[sf[i]] = last;
		if(si[sf[i]+1] > si[sf[i+1]+1]) last++;
	}

	cout << res << endl;
}
