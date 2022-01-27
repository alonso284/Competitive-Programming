// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1090

#include <iostream>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ C.cpp -std=c++17
*/

int n, p[200005], x, i, j, ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> p[i];
	sort(p, p+n);

	i = 0; j = n-1;
	while(i < j){
		if(p[i]+p[j]<=x)i++;
		ret++;
		j--;
	}
	cout << ret + (i==j);

	return 0;
}
