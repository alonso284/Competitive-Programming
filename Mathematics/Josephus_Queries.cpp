#include<iostream>

using namespace std;

int main(){
	int q; cin >> q;
	while(q--){
		int n, k; cin >> n >> k;

		if(k <= n/2){
			cout << 2*k << endl;
			continue;
		}

		int mov = n/2;
		int vuelta = 2;

		int cong = 0;
		pair<int, int> disp = {1, 3};
		bool prendido = (n/(1 << (vuelta - 2)))%2;	

		while(mov + (n-mov)/2 + (prendido &&  (n-mov)%2) < k){

			if(prendido){
				cong = disp.first;
				disp.first = disp.second;
			} else {
				cong = disp.second;
			}
			disp.second = disp.first + (1<<vuelta);

			mov += (n-mov)/2 + (prendido &&  (n-mov)%2);
			vuelta++;
			cout << prendido  << ' ' << mov <<  ' ' << disp.first << ' ' << disp.second << ' ' << cong << " - ";

			prendido = (n/(1 << (vuelta - 2)))%2;	
		}

		if(prendido){
			cong = disp.first;
		} else {
			cong = disp.second;
		}

		cout << (k-mov-1)*(1<<(vuelta)) + cong << endl;
	}
}
