// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/result/3465700/

#include <iostream>
#include <unordered_set>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ M.cpp -std=c++17
*/

int n, bitLim;
unordered_set <int> vis;

void printBin(int m){
	for(int i=0;i<bitLim;i++)
		cout << bool(m&(1<<i));
	cout << '\n';
}

void next(int m){
	vis.insert(m);
	printBin(m);
	for(int i=0;i<bitLim;i++)
		if(!vis.count(m^(1<<i)))
			next(m^(1<<i));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> bitLim;
	next(0);

	return 0;
}
