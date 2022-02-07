// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1641

#include <iostream>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ X.cpp -std=c++17
*/

int64_t n, k;
pair <int64_t, int64_t> a[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i].first;
		a[i].second=i+1;
	}
	sort(a,a+n);

	for(int i=0;i<n-2;i++){
		int ptr1=i+1, ptr2 = n-1;
		while(ptr1<ptr2){
			int64_t sum = a[i].first+a[ptr1].first+a[ptr2].first;
			if(sum == k){
				cout << a[i].second << ' ' << a[ptr1].second << ' ' << a[ptr2].second;
				return 0;
			}
			if(sum>k) ptr2--;
			if(sum<k) ptr1++;
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}