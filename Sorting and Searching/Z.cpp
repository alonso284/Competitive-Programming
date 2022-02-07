// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1645

#include <iostream>
#include <stack>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ Z.cpp -std=c++17
*/

int n, x[200005];
stack<pair<int,int>> leftSmallest;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++)
		cin >> x[i];

	for(int i=0;i<n;i++){
		while(!leftSmallest.empty()&&x[i]<=leftSmallest.top().first){
			leftSmallest.pop();
		}
		int temp = x[i];
		if(!leftSmallest.empty())
			x[i] = leftSmallest.top().second;
		else
			x[i]=0;
		leftSmallest.push({temp, i+1});
	}

	for(int i=0;i<n;i++)
		cout << x[i] << ' ';

	return 0;
}