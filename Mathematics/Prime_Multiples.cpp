#include <iostream>
#include <climits>
#include <vector>
 
using namespace std;

vector<long long> a;
vector<bool> comb;
long long n;
unsigned int k;
long long mcm = 1;

bool willOverflow(long long a) {
    return a > (LLONG_MAX / mcm);
}

long long ans = 0;
void group(unsigned int indx, bool parity){
	if(indx == k){
		ans += n/mcm * (parity? 1:-1);
		return;
	}

	group(indx + 1, parity);

	if(willOverflow(a[indx])) return;

	mcm *= a[indx];
	group(indx + 1, !parity);
	mcm /= a[indx];
}
 
int main(){

	cin >> n >> k;
	a.resize(k);
	comb.resize(k);

	for(long long &ai: a) cin >> ai;

	group(0, false);
	cout << ans + n;



 
	return 0;
}
