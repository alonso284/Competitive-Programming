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

#define lib pair < pair < long long, int >, bool >
long long Dijkstra(){
	priority_queue < lib, vector<lib>, greater<lib> > dijk;

	dijk.push(make_pair(make_pair(0,1), false));

	vector< pair <bool , bool > > vis(N+1, {false, false});

	while(dijk.top().first.second != N){
		pair < pair < long long, int > , bool  > fr = dijk.top();
		dijk.pop();
		long long d = fr.first.first;
		int u = fr.first.second;
		bool used = fr.second;

		/* cout << u << ' ' << d << ' ' << std::boolalpha << used << endl; */
		if(used){
			if(vis[u].first) continue;
			vis[u].first = true;
		} else {
			if(vis[u].second) continue;
			vis[u].second = true;
		}
		for(auto& [v, w]:aristas[u]){
			// si no lo haz vistado con el cupon usaod y el cupon no ha sido usado, usa el cupon
			/* cout << u << " -> " << v << endl; */
			if(vis[v].first == false && used == false) dijk.push({{d + w/2, v}, true});

			if(used){
				if(vis[v].first) continue;
				dijk.push({{d + w, v}, used});
			} else {
				if(vis[v].second) continue;
				dijk.push({{d + w, v}, used});
			}
		}
	}
	return dijk.top().first.first;
}
