// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2428

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> rep;
	int n, k; cin >> n >> k;
	int a[n];

	for(int i = 0; i < n; i++) cin >> a[i];

	int ptr1 = 0;
	long long res = 0;

	for(int ptr2 = 0; ptr2 < n; ptr2++){
		rep[a[ptr2]]++;
		while(rep.size() > k){
			map<int, int>::iterator it = rep.find(a[ptr1++]);
			if(--(it->second) == 0) rep.erase(it);
		}
		res += ptr2 - ptr1 + 1;
	}

	cout << res;

	return 0;
}
