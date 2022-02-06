// Alonso Huerta Escalante
// Link: https://cses.fi/problemset/task/2163

#include <iostream>
#include <set>
using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Sorting and Searching'
g++ Q.cpp -std=c++17
*/

int n, k, pos, q, temp;
int BIT[200005], ptr[200005];

int sum(int i){
	int res=0;
	for(;i>=0;i=(i&(i+1))-1)
		res+=BIT[i];
	return res;
}

void add(int indx, int delta){
	for(;indx<=n;indx=indx|(indx+1))
		BIT[indx]+=delta;
}

int binary(int ini, int fin, int indx){
	if(ini>=fin) return ini;
	int mit=(ini+fin)/2;
	
	if(sum(mit)>=indx) {
		return binary(ini, mit, indx);
	}
	else{
		return binary(mit+1,fin,indx);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for(int i=1;i<=n;i++){
		add(i,1);
		ptr[i]=i;
	}

	q=n;

	pos=1;
	while(q--){

		pos+=k;
		pos%=(q+1);
		if(pos==0) pos=q+1;

		temp = pos;
		temp = binary(1,n,temp);
		cout << temp << ' ';
		add(temp, -1);
		ptr[temp] = ptr[ptr[temp-1]];

	}




	return 0;
}
