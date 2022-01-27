// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1074

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ I.cpp -std=c++17
*/

int64_t n, bringDown, bringUp, MIN;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int64_t n;
	cin >> n;

	int64_t ar[n];
	for(int64_t i=0;i<n;i++) 
		cin >> ar[i];

	sort(ar,ar+n);

	for(int64_t i=0;i<n;i++)
		bringDown+=ar[i]-ar[0];

	MIN = bringDown;

	for(int64_t i=1;i<n;i++){
		bringDown-=(ar[i]-ar[i-1])*(n-i);
		bringUp+=(ar[i]-ar[i-1])*(i);
		MIN = min(MIN,bringDown+bringUp);
	}

	cout << MIN;


	return 0;
}
