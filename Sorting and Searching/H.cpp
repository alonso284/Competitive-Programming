// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1643

#include <iostream>
#include <utility>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ H.cpp -std=c++17
*/

int n;
int64_t sum, MAX=-1000000005;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		sum += x;
		MAX = max(MAX, sum);
		if(sum < 0) sum = 0;
	}
	cout << MAX;
	return 0;
}
