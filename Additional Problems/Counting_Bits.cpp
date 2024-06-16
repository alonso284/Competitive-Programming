#include <iostream>

using namespace std;

int main(){

	long long n; cin >> n;
	long long ans = 0;

	long long bit[52];
	bit[0] = 0;
	for(int i = 1; i <= 51; i++)
		bit[i] = bit[i-1]*2 + (1ll<<(i-1));

	for(int i = 51; i >= 1; i--){
		if(n >= (1ll<<i)-1){
			ans += bit[i];
			ans += n - ((1ll<<i)-1);
			n -= ((1ll<<i));
		}
	}
	cout << ans << endl;

	return 0;
}
