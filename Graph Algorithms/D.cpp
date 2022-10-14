// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1667

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
void BFS();
vector< vector<int> > aristas;
bool vis[100005];
int previous[100005];
vector<int> path;

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

	BFS();

	if(previous[N]){
		int node = N;
		while(node){
			path.push_back(node);
			node = previous[node];
		}
		reverse(path.begin(), path.end());
		cout << path.size() << endl;
		for(int i = 0; i < path.size(); i++){
			cout << path[i] << ' ';
		}
	}else{
		cout << "IMPOSSIBLE";
	}

	return 0;
}

void BFS(){
	queue<int>bfs;
	bfs.push(1);
	vis[1] = true;

	while(!bfs.empty()){
		int node = bfs.front();
		bfs.pop();

		for(auto& it:aristas[node]){
			if(!vis[it]){
				previous[it] = node;
				vis[it] = true;
				bfs.push(it);
			}
		}
	}
}
