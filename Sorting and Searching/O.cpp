// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1163

#include <iostream>
#include <map>
#include <set>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ O.cpp -std=c++17
*/

int x, n;
set<pair<int,int>>ranges;
map<int,int>rangeSizes;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> n;
	ranges.insert({0,x});
	ranges.insert({1000000005,1000000005});
	rangeSizes[x]++;

	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		auto it = ranges.upper_bound({temp,temp});
		it--;

		int l = it->first;
		int r = it->second;

		ranges.erase(it);

		if(--rangeSizes[r-l]==0) 
			rangeSizes.erase(r-l);

		ranges.insert({l,temp});
		ranges.insert({temp,r});
		rangeSizes[temp-l]++;
		rangeSizes[r-temp]++;

		auto MAX = rangeSizes.end();
		MAX--;
		cout << (MAX -> first) << ' ';
	}

	return 0;
}
