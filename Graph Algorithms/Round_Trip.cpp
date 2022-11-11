// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1669

#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector< vector<int> > aristas;
int op[100005];
void DFS(int node, int parent);
int res;
vector<int> path;
bool vis[100005];

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
		if(!op[i] && !vis[i]) DFS(0, i);
	}	


	if(res){
		int node = op[res];
		path.push_back(res);
		while(node!=res){
			path.push_back(node);
			node = op[node];
		}
		path.push_back(node);
		cout << path.size() << endl;
		for(auto& it:path){
			cout << it << ' ';
		}
	}else cout << "IMPOSSIBLE";

	return 0;
}

void DFS(int parent, int node){
	vis[node] = true;
	if(op[node]){
		res = node;
		return;
	}

	for(auto &it:aristas[node]){
		if(it == parent || res) continue;
		
		op[node] = it;
		DFS(node, it);
		if(!res)op[node] = 0;

	}
}
