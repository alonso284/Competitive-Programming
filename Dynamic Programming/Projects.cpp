#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>
#include <cstring>

using namespace std;

typedef array<int, 3> job;
int const MAXN = 200005;
int n;
long long dp[MAXN];

vector<job> jobs;

long long DP(int indx){
	if(indx == n) return 0;
	if(dp[indx] == -1){
		int p = lower_bound(jobs.begin(), jobs.end(), job{jobs[indx][1]+1, jobs[indx][1]+1, 0}) - jobs.begin();
		dp[indx] = max(DP(p)+jobs[indx][2], DP(indx+1));
	}
	return dp[indx];
}

int main(){

	memset(dp, -1, sizeof(dp));
	cin >> n;
	jobs.resize(n);
	for(job &j: jobs)
		cin >> j[0] >> j[1] >> j[2];

	sort(jobs.begin(), jobs.end());

	cout << DP(0);




	return 0;
}


