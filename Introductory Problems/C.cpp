// Alonso Huerta Escalante Jan 29, 2022 at 14:12
// Link: https://cses.fi/problemset/task/1069

#include <iostream>
#include <string>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Introductory Problems'
g++ C.cpp -std=c++17
*/

int n, t=1, c=1;
string adn;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> adn;
	for(int i=0;i<adn.size()-1;i++){
		if(adn[i]==adn[i+1])
			c++;
		else c=1;
		if(c>t) t=c;
	}

	cout << t;

	return 0;
}
