// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1636

#include<iostream>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

const int MAXN = 1e6;
const int MOD = 1e9+7;
int DP[MAXN];
int n, x;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP, 0, sizeof(DP));
	DP[0] = 1;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		int c; cin >> c;
		for(int w = c; w <= x; w++){
			DP[w] += DP[w-c];
			DP[w] %= MOD;
		}
	}
	cout << DP[x];


	return 0;
}


