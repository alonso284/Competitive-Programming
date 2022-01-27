// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/1163

#include <iostream>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ Z.cpp -std=c++17
*/

int NEXT[200005], PREV[200005], N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	NEXT[N] = 1;
	PREV[1] = N;

	for(int i = 1; i < N; i++){
		NEXT[i] = i+1;
		PREV[i+1] = i;
	}

	int current = 1;
	while(N--){
		current = NEXT[current];
		cout << current << ' ';
		NEXT[PREV[current]] = NEXT[current];
		PREV[NEXT[current]] = PREV[current];
		current = NEXT[current];
	}

	return 0;
}
