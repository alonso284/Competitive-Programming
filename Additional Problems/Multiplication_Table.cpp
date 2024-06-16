#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	long long n; cin >> n;



	// I want the one at position (n*n+1)/2
	long long limit = (n*n+1)/2;
	long long i = 0;
	for(; i <= n; i++){
		if(i*i >= limit){
			break;
		}
	}

	vector<long long> ans;
	for(long long j = 1; j < n; j++){
		ans.push_back(i*j);
		ans.push_back(i*j);
	}
	ans.push_back(i*i);
	sort(ans.begin(), ans.end());

	cout << ans[limit - (i-1)*(i-1) - 1] << endl;

	return 0;
}

