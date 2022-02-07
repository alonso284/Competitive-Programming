// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1631

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ W.cpp -std=c++17
*/

int64_t n, ptr1, ptr2, t[200005], temp, sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++)
		cin >> t[i];
 
	sort(t, t+n);

	for(int i=0;i<n-1;i++){
		sum+=t[i];
	}

	temp=t[n-1];

	if(sum>=temp) cout << sum+temp;
	else{
		cout << 2*temp;
	}





	return 0;
}