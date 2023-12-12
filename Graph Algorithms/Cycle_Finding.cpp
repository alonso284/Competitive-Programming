#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

#define INF LLONG_MAX

int main(){
	
	int N, M;
	cin >> N >> M;

	vector< vector < pair< int, long long > > > AL(N+1);

	while(M--){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		AL[a].push_back({b, c});
	}

	vector<long long> dist(N+1);
	vector<int> p(N+1, -1);
	dist[1] = 0;

	for(int i = 0; i < N; i++){
		bool modified = false;
		for(int u = 1; u <= N; u++){
			for(auto &[v, w]: AL[u]){
				if(dist[u] + w >= dist[v]) continue;
				p[v] = u;
				dist[v] = dist[u] + w;
				modified = true;
			}
		}
		if(!modified) break;
	}


	int node = -1;
	for(int u = 1; u <= N; u++){
		/* cout << u << ' ' << dist[u] << endl; */
		if(dist[u] == INF) continue;
		for(auto &[v, w]: AL[u])
			if(dist[u] + w < dist[v])
				node = v;
	}

	/* for(int i = 1; i <= N; i++) cout << i << ' ' << p[i] << endl; */

	if(node == -1){
		cout << "NO";
	} else {
		cout << "YES" << endl;
		vector<bool> vis(N+1, false);
		stack<int> path;

		while(!vis[node]){
			path.push(node);
			vis[node] =true;
			node = p[node];
		}
		cout << node << ' ';
		while(!path.empty() && path.top() != node){
			cout << path.top() << ' '; path.pop();
		}
		cout << node;
	}

	return 0;
}
