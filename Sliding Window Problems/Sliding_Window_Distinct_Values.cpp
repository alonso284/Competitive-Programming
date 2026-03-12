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

map<int, int> freq;

void add(int x){
	freq[x]++;
}

void remove(int x){
	if(--freq[x] == 0) freq.erase(x);
}

int value(){
	return (int)freq.size();
}

int main(){
	int x; 
	int n; cin >> n;
	int k; cin >> k;

	deque<int> dq;
	for(int i = 1; i < k; i++){
		cin >> x;
		dq.push_back(x);
		add(x);
	}

	for(int i = k; i <= n; i++){
		cin >> x;
		add(x);
		dq.push_back(x);
		cout << value() << ' ';

		remove(dq.front());
		dq.pop_front();
	}
}
