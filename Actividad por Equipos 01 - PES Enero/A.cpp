#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cmath>

using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Actividad por Equipos 01 - PES Enero'
g++ A.cpp -std=c++17
*/

int accu[5005], N, M;

bool goodLuck(int n){
	bool rep[10] = {0};
	while(n){
		if(rep[n%10]) return false;
		else rep[n%10] = true;
		n /= 10;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1; i < 5005; i++) 
		accu[i] = accu[i-1] + goodLuck(i);

	while(cin >> N >> M) 
		cout << accu[M] - accu[N-1] << '\n';

	return 0;
}
