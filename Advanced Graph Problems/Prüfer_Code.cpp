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
	vector<int> code(n-2);
	vector<int> freq(n+1);

	for(int &it: code)
		cin >> it, freq[it]++;

	priority_queue<int, vector<int>, greater<int>> leafs;
	for(int i = 1; i <= n; i++)
		if(!freq[i])
			leafs.push(i);

	for(const int &it: code){
		int leaf = leafs.top(); leafs.pop();
		cout << leaf << ' ' << it << endl;
		if(!--freq[it]) leafs.push(it);
	}
	cout << leafs.top() << ' ' << n << endl;
}
