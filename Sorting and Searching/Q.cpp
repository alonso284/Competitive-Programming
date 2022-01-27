// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2163

#include <iostream>
#include <vector>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ .cpp -std=c++17
*/

int n, k;
vector<int>circle;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for(int i=1;i<=n;i++)
		circle.push_back(i);

	int pos = 0;
	while(!circle.empty()){
		pos+=k;
		pos%=circle.size();

		cout << circle[pos] << ' ';
		circle.erase(circle.begin()+pos);
	}


	return 0;
}
