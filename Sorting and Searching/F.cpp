// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1629

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ F.cpp -std=c++17
*/

struct inter{
	int start, end;
}ab[200005];

bool operator < (inter u, inter v){ return u.end < v.end;}

int n, movies;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++) cin >> ab[i].start >> ab[i].end;
	sort(ab, ab+n);

	inter current;
	current.start = current.end = 0;
	for(int i=0;i<n;i++){
		if(current.end <= ab[i].start){
			current = ab[i];
			movies++;
		}
	}

	cout << movies;

	return 0;
}
