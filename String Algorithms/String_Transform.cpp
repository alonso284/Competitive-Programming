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

array<int, 27> dq;
array<int, 27> temp;

int main(){
	string e; cin >> e;
	for(char &c: e) if(c == '#') c = 'a'-1;
	string b = e;
	sort(b.begin(), b.end());
	const int n = e.size();

	vector<array<int, 27>> freq(n, temp);

	for(int i = 0; i < n; i++)
		dq[b[i]-('a'-1)]++, freq[i][e[i]-('a'-1)]++;


	for(int i = 1; i < n; i++)
	for(int l = 0; l < 27; l++)
		freq[i][l] += freq[i-1][l];
	for(int l = 1; l < 27; l++)
		dq[l] += dq[l-1];

	string res;
	for(int idx = 0; res.size() < n; idx = dq[e[idx]-('a'-1)-1] + freq[idx][e[idx]-('a'-1)]-1)
		res.push_back(b[idx]);

	reverse(res.begin(), res.end());
	res.pop_back();
	cout << res << endl;

	return 0;
}
