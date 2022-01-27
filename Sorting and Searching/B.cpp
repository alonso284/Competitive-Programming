// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1084

#include <iostream>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ B.cpp -std=c++17
*/

int a[200005], b[200005], n, m, k, ret, i, j;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++) 
		cin >> b[i];
	
	sort(a, a+n);
	sort(b, b+m);

	while(i < n && j < m){
		if(a[i]-k <= b[j] && b[j] <= a[i]+k){
			ret++; i++; j++;
			continue;
		}

		if(b[j] < a[i]-k){ 
			j++;
			continue;
		}

		i++;
	}

	cout << ret;

	return 0;
}
