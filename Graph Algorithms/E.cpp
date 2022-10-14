// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1668

#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector< vector<int> > aristas;
short signed int colors[100005];
void DFS(int node, int color);
bool possible = true;

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
		if(!colors[i]) DFS(i,1);
	}

	if(possible){
		for(int i = 1 ; i <= N; i++){
			cout << colors[i] << ' ';
		}
	}else{
		cout << "IMPOSSIBLE";
	}

	return 0;
}

void DFS(int node, int color){
	if(colors[node]){
		if(colors[node] != color) possible = false;
		return;
	}
	
	colors[node] = color;

	for(auto& it:aristas[node]){
		DFS(it, (color==1? 2:1));
	}

}
