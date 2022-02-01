// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1094

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ D.cpp -std=c++17
*/

int n, pre, pos;
int64_t t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> pre;
	for(int i=1;i<n;i++){
		cin >> pos;
		if(pre>pos){
			t+=pre-pos;
			pos=pre;
		}
		swap(pre, pos);
	}

	cout << t;

	return 0;
}
