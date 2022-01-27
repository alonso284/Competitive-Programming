// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/result/3426796/

#include <iostream>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ K.cpp -std=c++17
*/

bool ar[200005];
int n, rounds;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		ar[temp]=true;
		rounds+=!(ar[temp-1]);
	}

	cout << rounds;

	return 0;
}
