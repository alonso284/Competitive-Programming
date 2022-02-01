// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1617/

#include <iostream>
using namespace std;
#define MOD 1000000007

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ I.cpp -std=c++17
*/

int64_t n, res=1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=1;i<=n;i++){
		res+=res;
		res%=MOD;
	}

	cout << res;

	return 0;
}
