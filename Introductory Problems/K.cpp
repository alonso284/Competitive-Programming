// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1754

#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ K.cpp -std=c++17
*/

int64_t tt, a, b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tt;
	while(tt--){
		cin >> a >> b;
		cout << ((max(a,b)-2*abs(a-b))%3==0 && (max(a,b)-2*abs(a-b))>=0?"YES":"NO") << '\n';
	}

	return 0;
}
