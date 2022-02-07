// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2163

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ Q.cpp -std=c++17
*/

int n, k, pos, q, temp;
int BIT[200005];



void add(int indx, int delta){
	for(;indx<=n;indx+=indx&(-indx))
		BIT[indx]+=delta;
}

int metabinary(int x){
	int i=0; int bit = (1<<(int(log2(n)))); int sum = 0;
	for(;bit;bit/=2){
		if(i+bit>n) continue;
		if(BIT[i+bit]+sum<x){ i+=bit; sum+=BIT[i]; }
	}
	return i+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for(int i=1;i<=n;i++){
		add(i,1);
	}

	q=n;
	pos=1;

	while(q--){

		pos+=k;
		pos%=(q+1);
		if(pos==0) pos=q+1;

		temp = metabinary(pos);
		cout << temp << ' ';
		add(temp, -1);

	}

	return 0;
}
