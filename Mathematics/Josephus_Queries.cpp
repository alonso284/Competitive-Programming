#include <iostream>
#include <vector>

using namespace std;

void bin(long long n){
	for(int i = 20; i >= 0; i--){
		cout << (bool)(n & (1<<i));
	}
}

int main(){

	int q; cin >> q;
	while(q--){
		int k, n; cin >> n >> k;


	}
}
