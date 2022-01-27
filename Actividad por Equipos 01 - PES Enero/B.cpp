#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cmath>

using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Actividad por Equipos 01 - PES Enero'
g++ B.cpp -std=c++17
*/

bool ar[181];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ar[0]=true;
	int mn = 1, hr = 0;
	for(int i=1;i<=720;i++){
		ar[min(abs(hr%60-mn%60), 60-abs(hr%60-mn%60))*6] = true;
		mn++;
		if(i%12==0) hr++;
	}
	int n;
	while(cin >> n){
		cout << (ar[n]?'Y':'N') << '\n';
	}

	return 0;
}
