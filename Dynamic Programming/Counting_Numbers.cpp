#include <iostream>
#include <cmath>
#include <string>

// FIXME 009, 008, 007 are discounted

using namespace std;

string a, b;

long long comb(string &n, int indx){
	if(indx == n.size()) return 1;

	// escoger uno que sea menor al actaul
	int cant_op = n[indx] - '0';
	if(indx && n[indx-1] < n[indx]) cant_op--;

	long long ans = pow(9, n.size()-indx-1) * cant_op;

	// checar si aun puedo poner el numero
	if(!indx || n[indx-1] != n[indx]) ans += comb(n, indx+1);

	return ans;
}

int main(){

	long long a, b; cin >> a >> b;
	string sa = to_string(a-1);
	string sb = to_string(b);

	if(!b){
		cout << 1;
		return 0;
	}

	cout << comb(sb, 0) - (a? comb(sa, 0):0) << endl;

	return 0;
}
