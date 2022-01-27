// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1621

#include <iostream>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ A.cpp -std=c++17
*/

int x[200005];
int N, ret, xi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> x[i];
	sort(x+1, x+N+1);
	for(int i = 0; i < N; i++) ret += (x[i]!=x[i+1]);
	cout << ret;

	return 0;
}
