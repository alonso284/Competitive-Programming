// Alonso Huerta Escalante
// https://cses.fi/problemset/task/1671

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector < vector< pair < int, long long > > > aristas;
long long l[100005];
bool vis[100005];
void BFS();

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	aristas.resize(N+1);

	while(M--){
		int a, b , c; cin >> a >> b >> c;
		aristas[a].push_back(make_pair(b, c));
	}

	BFS();

	for(int i = 1; i <= N; i++)
		cout << l[i] << ' ';

	return 0;
}

void BFS(){
	priority_queue < pair < long long, int > > dijkstra;

	dijkstra.push(make_pair(0, 1));
	while(!dijkstra.empty()){
		pair < long long, int  > fr = dijkstra.top();
		dijkstra.pop();
		if(vis[fr.second]) continue;
		vis[fr.second] = true;
		l[fr.second] = -fr.first;
		for(auto& it:aristas[fr.second]){
			if(!vis[it.first]){
				dijkstra.push(make_pair(fr.first - it.second, it.first));
			}
		}
	}
}
