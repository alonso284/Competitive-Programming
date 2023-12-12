#include <iostream>
#include <vector>
#include <map>
#include <climits>

#define vi vector < int64_t >
#define INF LLONG_MAX

using namespace std;

int main(){
	int V, E;
	cin >> V >> E;
	vector < map < int, int64_t > > AL;

	AL.resize(V);
	while(E--){
		int a, b;
		int64_t c;
		cin >> a >> b >> c;
		

		if(!AL[a-1].count(b-1) ) AL[a-1][b-1] = -c;
		else AL[a-1][b-1] = min(AL[a-1][b-1], -c);
	}

	vi dist(V, INF); dist[0] = 0 ;

	for(int i=0;i<V-1; ++i) {
		bool modified = false; 
		for(int u=0;u<V; u++)
		if (dist[u] != INF)
			for (auto &[v, w] : AL[u]) {
				if (dist[u]+w >= dist[v]) continue;
					dist[v] = dist[u]+w;
					modified = true;
			}
  		if (!modified) break;
	}

	/* bool hasNegativeCycle = false; */
	vector<bool> cycle(V, false);
	for (int u = 0; u < V; ++u){
		/* cout << u << '-' << dist[u] << endl; */
		if (dist[u] != INF)
			for (auto &[v, w] : AL[u])
		 		if (dist[v] > dist[u]+w)
					cycle[v] = true;
					/* hasNegativeCycle = true; */
	}

	for(int i=0;i<V-1; ++i) {
		bool modified = false; 
		for(int u=0;u<V; u++)
		if (cycle[u])
			for (auto &[v, w] : AL[u]) {
				cycle[v] = true;
					modified = true;
			}
  		if (!modified) break;
	}

	if (cycle[V-1])
		cout << -1;
	else 
		cout << -dist[V-1];
}
