// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/2165

#include <iostream>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ N.cpp -std=c++17
*/

int n;

void solveFor(int size, int current, int pivot, int final){
	if(size==0) return;
	if(size==1){
		cout << current << ' ' << final << '\n';
		return;
	}

	for(int i=size;0<i;i--){
		if(i%2){ 
			solveFor(1, current, pivot, final);
			solveFor(size-i, pivot, current, final);
		}
		else{ 
			solveFor(1, current, final, pivot);
			solveFor(size-i, final, current, pivot);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << (1<<(n))-1 << '\n';
	solveFor(n,1,2,3);

	return 0;
}
