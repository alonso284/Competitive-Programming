// Alonso Huerta Escalante
// https://cses.fi/problemset/task/1195

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

vector < vector < pair < int, long long > > > aristas;
int N, M;
long long Dijkstra();
bool vis[100005][2];
// set < pair<int,int> > vis;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	aristas.resize(N+1);

	while(M--){
		int a, b, c;
		cin >> a >> b >> c;
		aristas[a].push_back(make_pair(b,c));
	}

	cout << Dijkstra();

	return 0;
}

long long Dijkstra(){
	priority_queue < pair < pair < long long, long long >, int > > dijk;
	dijk.push(make_pair(make_pair(0,0), 1));

	while(dijk.top().second != N){
		pair < pair < long long, long long > , int > fr = dijk.top();
		dijk.pop();

		// if(vis.count(make_pair(fr.second))) continue;
		// vis[fr.second] = true;
		// cout << "THE TOP IS " << fr.first.first << ' ' << fr.first.second << endl;

		long long maxPath = -fr.first.second;
		long long actualPrize = -fr.first.first + maxPath/2 + maxPath%2;

		// cout << "estoy en " << fr.second << " para llegar aqui desconte " << maxPath/2 + maxPath%2 << " pero el real cuesta " << actualPrize << " y " << -fr.first.first  <<  endl;
		for(auto& it:aristas[fr.second]){
			if(!vis.count(make_pair(fr.second, it.first)))
				vis.insert(make_pair(fr.second, it.first));
				// cout << "agregando " << it.first << " estando en " << fr.second << endl;  
				dijk.push(make_pair(make_pair(-(actualPrize + it.second - max(maxPath, it.second)/2 - max(maxPath, it.second)%2), -max(maxPath, it.second)),it.first));
		}
	}
	return -dijk.top().first.first;
}
