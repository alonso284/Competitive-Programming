#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

#define COM ((1<<n)-1)
#define EMP 0
map<int, vector<int> > transition;

int n, m;
void trans(int current, int bit, int next){
	if(bit == n){
		if(next == COM) return;
		transition[current].push_back(next);
		return;
	}

	if(current & (1<<bit)){
		trans(current, bit+1, next);
	}
	else{
		trans(current, bit+2, next | (1<<bit) | (1<<(bit+1)));
		trans(current, bit+2, next);
	}
}

void binary(int mask){
	for(int i = 0; i < n; i++)
		cout << (bool)(mask & (1<<i));
	cout << endl;
}


long long dp[1<<10][1003];
bool vis[1<<10][1003];
int DP(int mask, int row){
	/* if(row == m-1 && mask == COM) return 1; */
	if(row == m && mask == EMP) return 1;
	if(row >= m) return 0;

	if(vis[mask][row]) return dp[mask][row];
	vis[mask][row] = true;

	if(mask == EMP){
		dp[mask][row] = DP(EMP, row+2);
		for(auto p: transition){
			dp[mask][row] += DP(p.first, row+1);
		}
	} else {
		dp[mask][row] = DP(EMP, row+1);
		for(int i : transition[mask]){
			dp[mask][row] += DP(i, row+2);
		}
	}

	return dp[mask][row] %= 1000000007;

}

int main(){

	cin >> n >> m;

	for(int i = 0; i < (1<<n)-1; i++){
		int mask = i + (1<<n);
		bool flag = true;
		for(int bit = 0; bit < n; bit++){
			if((mask & (1<<bit)) == 0){
				bit++;
				if((mask & (1<<bit))){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			transition[i] = vector<int>();
			trans(i, 0, i);
		}
	}

	for(auto p : transition){
		binary(p.first);
		for(int i : p.second)
			binary(i);
		cout << endl;
	}


	/* for(int i = 0; i < (1<<n); i++){ */
	/* 	for(int j = 0; j < (1<<m); j++){ */
	/* 	} */
	/* } */

	cout << DP(0, 0) << endl;	

	return 0;
}
