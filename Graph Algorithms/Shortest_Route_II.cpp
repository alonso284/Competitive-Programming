#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define iii pair< long, pair < int, int > >
#define ii pair< long, long >
#define vi vector<long long>
#define vii vector< pair < long, long > >
#define INF ((long long)(1e9) * 505)

using namespace std;

int N, M, Q;
vector < vector < long long > > AM;


int main(){
	cin >> N >> M >> Q;
	AM.assign(N+1, vector<long long>(N+1, INF));

	while(M--){
		int a, b;
		long long c;

		cin >> a >> b >> c;

		AM[a][b] = min(AM[a][b], c);
		AM[b][a] = min(AM[b][a], c);
	}

	for(int k = 0; k <= N; k++)
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);

	while(Q--){
		int i, j; cin >> i >> j;
		if(i == j){
			cout << 0 << endl;
			continue;
		}
		cout << (AM[i][j] == INF? -1: AM[i][j]) << endl;
	}



}
