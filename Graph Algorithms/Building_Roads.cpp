// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1666

#include<iostream>
#include <vector>

using namespace std;

int N, M;
vector< vector<int> > aristas;
bool vis[100005];
void DFS(int node);
vector<int> conn;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	aristas.resize(N+1);

	while(M--){
		int u, v; cin >> u >> v;
		aristas[u].push_back(v);
		aristas[v].push_back(u);
	}

	for(int i = 1; i <= N; i++){
		if(!vis[i]){
			conn.push_back(i);
			DFS(i);
		}
	}

	cout << conn.size() - 1 << endl;
	for(int i = 1; i < conn.size(); i++){
		cout << conn[i] << ' ' << conn[i-1] << endl;
	}

	return 0;
}

void DFS(int node){
	vis[node] = true;

	for(auto &it:aristas[node]){
		if(!vis[it]) DFS(it);
	}
}
