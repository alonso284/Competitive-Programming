// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1619

#include <iostream>
#include <map>
#include <utility>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ E.cpp -std=c++17
*/

int n, MAX;
map<int,int> TIME;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	TIME[0]=0;
	while(n--){
		int a, b;
		cin >> a >> b;
		TIME[a]++;
		TIME[b]--;
	}

	auto it=TIME.lower_bound(0);
	it++;
	for(;it!=TIME.end();it++){
		auto prev = it;
		prev--;
		it->second+=prev->second;
		MAX = max(MAX, it->second);
	}

	cout << MAX;



	return 0;
}
