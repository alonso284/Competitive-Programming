// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1755

#include <iostream>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ L.cpp -std=c++17
*/

int64_t n, ar[26];
char odd, temp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin >> temp){
		ar[temp-'A']++;
	}

	for(int i=0;i<26;i++){
		if(ar[i]%2){
			if(odd){
				cout << "NO SOLUTION";
				return 0;
			}
			odd = i+1;
		}
		ar[i]/=2;
	}

	for(int i=0;i<26;i++)
		for(int j=0;j<ar[i];j++)
			cout << char(i+'A');

	if(odd) cout << char(odd+'A'-1);

	for(int i=26-1;i>=0;i--)
		for(int j=0;j<ar[i];j++)
			cout << char(i+'A');

	return 0;
}
