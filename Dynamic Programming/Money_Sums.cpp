#include <iostream>

using namespace std;
const int MAXSUM = 100005;
bool dp[MAXSUM];

int main(){

	int n;
	cin >> n;
	dp[0] = true;
	int ans = 0;
	while(n--){
		int x; cin >> x;
		for(int i = MAXSUM-1; i >= 0; i--)
			if(dp[i] && !dp[i+x])
				dp[i+x] = (bool)++ans;
	}

	 cout << ans << endl;
	 for(int i = 1; i < MAXSUM; i++)
		 if(dp[i]) cout << i << ' ';
	



	return 0;
}
