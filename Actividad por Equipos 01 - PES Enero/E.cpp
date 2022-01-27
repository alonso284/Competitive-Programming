#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Actividad por Equipos 01 - PES Enero'
g++ E.cpp -std=c++17
*/

int N;


void BFS(int node, unordered_set < int >& graph, vector < vector < int > >& ady){
	queue <int> bfs;
	bfs.push(node);
	while(!bfs.empty()){
		for(auto& child:ady[bfs.front()])
			if(!graph.count(child)){
				graph.insert(child);
				bfs.push(child);
			}
		bfs.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin >> N){
		// ady.clear();
		// ady.resize((2*N+1)*(2*N));
		// graph.clear();
		unordered_set < int > graph;
		vector < vector < int > > ady((2*N+1)*(2*N));

		for(int i = 1; i < 2*N; i+=2){
			ady[i].push_back(i+1);
			ady[i+1].push_back(i);
		}

		for(int i = 0; i < 2*N-1; i++){
			string line;
			cin >> line;
			for(int j = 0; j < N; j++){
				char cmd = line[j];

				if(cmd == 'H'){
					ady[i*(2*N+1)+j*2+i%2].push_back(i*(2*N+1)+j*2+1+i%2);
					ady[i*(2*N+1)+j*2+1+i%2].push_back(i*(2*N+1)+j*2+i%2);

					ady[(i+1)*(2*N+1)+j*2+i%2].push_back((i+1)*(2*N+1)+j*2+1+i%2);
					ady[(i+1)*(2*N+1)+j*2+1+i%2].push_back((i+1)*(2*N+1)+j*2+i%2);
				}else{
					ady[i*(2*N+1)+j*2+i%2].push_back((i+1)*(2*N+1)+j*2+i%2);
					ady[(i+1)*(2*N+1)+j*2+i%2].push_back(i*(2*N+1)+j*2+i%2);

					ady[i*(2*N+1)+j*2+1+i%2].push_back((i+1)*(2*N+1)+j*2+1+i%2);
					ady[(i+1)*(2*N+1)+j*2+1+i%2].push_back(i*(2*N+1)+j*2+1+i%2);
				}
			}
			if(i%2){
				ady[i*(2*N+1)].push_back((i+1)*(2*N+1));
				ady[(i+1)*(2*N+1)].push_back(i*(2*N+1));
			}else{
				ady[i*(2*N+1)+2*N].push_back((i+1)*(2*N+1)+2*N);
				ady[(i+1)*(2*N+1)+2*N].push_back(i*(2*N+1)+2*N);
			}
		}

		for(int i = 1; i < 2*N; i+=2){
			ady[i+(2*N-1)*(2*N+1)].push_back(i+1+(2*N-1)*(2*N+1));
			ady[i+1+(2*N-1)*(2*N+1)].push_back(i+(2*N-1)*(2*N+1));
		}

		int boxCount = 0;
		for(int i = 0; i < (2*N+1)*(2*N); i++){
			if(!graph.count(i)){
				graph.insert(i);
				boxCount++;
				BFS(i, graph, ady);
			}
		}

		cout << boxCount-1 << '\n';
	}

	return 0;
}
