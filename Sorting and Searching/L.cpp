// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2217

#include <iostream>
#include <cmath>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ L.cpp -std=c++17
*/

int ar[200005];
int n,m,rounds=1, OG[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	OG[n+1] = n+1;

	for(int i=1;i<=n;i++){
		int temp;
		cin >> temp;
		ar[temp] = i;
		OG[i]=temp;
	}

	for(int i=1;i<=n;i++){
		if(ar[i] < ar[i-1]) rounds++;
	}

	while(m--){
		int a, b, x1, x2;
		cin >> a >> b;
		x1 = OG[a]; x2 = OG[b];

		if(x1+1==x2){
			if(ar[x1-1] > ar[x1]) rounds--;
			if(ar[x1] > ar[x2]) rounds--;
			if(ar[x2] > ar[x2+1]) rounds--;
		}
		else if(x2+1==x1){
			if(ar[x2-1] > ar[x2]) rounds--;
			if(ar[x2] > ar[x1]) rounds--;
			if(ar[x1] > ar[x1+1]) rounds--;
		}else{
			if(ar[x1] > ar[x1+1]) rounds--;
			if(ar[x1-1] > ar[x1]) rounds--;

			if(ar[x2] > ar[x2+1]) rounds--;
			if(ar[x2-1] > ar[x2]) rounds--;
		}

		OG[a] = x2;
		OG[b] = x1;
		ar[x1] = b;
		ar[x2] = a;

		if(x1+1==x2){
			if(ar[x1-1] > ar[x1]) rounds++;
			if(ar[x1] > ar[x2]) rounds++;
			if(ar[x2] > ar[x2+1]) rounds++;
		}
		else if(x2+1==x1){
			if(ar[x2-1] > ar[x2]) rounds++;
			if(ar[x2] > ar[x1]) rounds++;
			if(ar[x1] > ar[x1+1]) rounds++;
		}else{
			if(ar[x1] > ar[x1+1]) rounds++;
			if(ar[x1-1] > ar[x1]) rounds++;

			if(ar[x2] > ar[x2+1]) rounds++;
			if(ar[x2-1] > ar[x2]) rounds++;
		}

		cout << rounds << '\n';


	}

	return 0;
}
