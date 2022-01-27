// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2183

#include <iostream>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ J.cpp -std=c++17
*/

int64_t n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int64_t ar[n+1];
	ar[n]=0;
	for(int64_t i=0;i<n;i++)
		cin >> ar[i];

	sort(ar,ar+n);

	if(ar[0]!=1){
		cout << 1;
		return 0;
	}

	int64_t k = 1;
	for(int64_t i=1;i<n;i++){
		k+=ar[i];
		if(k<ar[i+1]-1) break;
	}

	cout << k+1;

	return 0;
}
