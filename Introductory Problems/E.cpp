// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1070

#include <iostream>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ E.cpp -std=c++17
*/

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if(n==2||n==3){
		cout << "NO SOLUTION";
		return 0;
	}
	if(n==5){
		cout << "4 2 5 3 1";
		return 0;
	}
	if(n==4){
		cout << "3 1 4 2";
		return 0;
	}

	if(n%2){
		cout << n << ' ';
		n--;
	}

	for(int i=1;i<=n/2;i++){
		cout << i << ' ' << n/2+i << ' ';
	}

	return 0;
}
