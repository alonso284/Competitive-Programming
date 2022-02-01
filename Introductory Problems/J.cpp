// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1618

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ J.cpp -std=c++17
*/

int64_t n, fives;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=5;i<=n;i*=5)
		for(int j=i;j<=n;j+=i)
			fives++;

	cout << fives;
	

	return 0;
}
