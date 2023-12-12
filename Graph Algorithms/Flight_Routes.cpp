#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define li pair<long long, int>
#define INF LLONG_MAX

int main(){

	int N, M, K; cin >> N >> M >> K;

	vector< vector < pair < int, long long > > > AL(N+1);
	while(M--){
		int a, b; long long c;
		cin >> a >> b >> c;
		AL[a].push_back({b, c});
	}

	vector< vector <long long > > dist(N+1, vector<long long>(K, INF)); dist[1].front() = 0;
	priority_queue< li, vector< li >, greater< li > > pq;
	pq.emplace(0, 1);

	while(!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();

		 if (d > dist[u].back()) continue;

		for(const auto &[v, w]:AL[u]){
			if (d+w >= dist[v].back()) continue;
			 dist[v].back() = d+w;
			 pq.emplace(dist[v].back(), v);
			 sort(dist[v].begin(), dist[v].end());
		}

	}

	for(long long &it: dist[N])
		cout << it << ' ';


	return 0;
}
