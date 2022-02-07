// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1630 

#include <iostream>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ V.cpp -std=c++17
*/

int64_t n, res, T;
pair<int64_t, int64_t> df[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> df[i].first >> df[i].second;
	}

	sort(df, df+n);

	for(int i=0;i<n;i++){
		T += df[i].first;
		res += (df[i].second-T);
	}

	cout << res;


	return 0;
}