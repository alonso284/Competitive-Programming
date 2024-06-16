#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

const int MAXN = 5005;

long long dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

long long DP(int i, int j, long long sum){
	if(i>j) return 0;

	if(!vis[i][j]){
		vis[i][j] = true;

		dp[i][j] = max(sum - DP(i+1, j, sum-x[i]), sum - DP(i, j-1, sum-x[j]));
	}

	return dp[i][j];
}

int main(){

	cin >> n;
	x.resize(n);
	long long sum = 0;
	for(int &it: x) {
		cin >> it;
		sum += it;
	}

	cout << DP(0, n-1, sum);

	return 0;
}
