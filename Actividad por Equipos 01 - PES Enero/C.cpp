#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*
cd Documents/Github/Competitive-Programming/'Actividad por Equipos 01 - PES Enero'
g++ C.cpp -std=c++17
*/

int ar[100001];
vector < pair <int, int > > SegmentTree;

void setUp(int n, int ini, int fin){
	if(ini == fin){
		if(ar[ini] < 0) SegmentTree[n].first=1;
		else SegmentTree[n].first=0;

		if(ar[ini] == 0) SegmentTree[n].second=1;
		else SegmentTree[n].second=0;

		return;
	}

	int mit = (ini+fin)/2;
	setUp(n*2, ini, mit);
	setUp(n*2+1, mit+1, fin);
	SegmentTree[n].first = SegmentTree[n*2].first + SegmentTree[n*2+1].first;
	SegmentTree[n].second = SegmentTree[n*2].second + SegmentTree[n*2+1].second;
}

void upDate(int n, int ini, int fin, int x){
	if(ini == fin){
		if(ar[ini] < 0) SegmentTree[n].first=1;
		else SegmentTree[n].first=0;

		if(ar[ini] == 0) SegmentTree[n].second=1;
		else SegmentTree[n].second=0;

		return;
	}

	int mit = (ini+fin)/2;
	if(ini <= x && x <= mit) upDate(n*2, ini, mit, x);
	else upDate(n*2+1, mit+1, fin, x);

	SegmentTree[n].first = SegmentTree[n*2].first + SegmentTree[n*2+1].first;
	SegmentTree[n].second = SegmentTree[n*2].second + SegmentTree[n*2+1].second;
}

pair<int, int> query(int n, int ini, int fin, int l, int r){
    if(r < ini || l > fin)
        return {0, 0};
    if(l <= ini && fin <= r)
        return SegmentTree[n];

    int mit=(ini+fin)/2;
    pair<int, int> p1=query(2*n, ini, mit, l, r);
    pair<int, int> p2=query(2*n+1, mit+1, fin, l, r);
    return {p1.first+p2.first, p1.second+p2.second};
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	while(cin >> n >> k){
		SegmentTree.clear();
		SegmentTree.resize(4*n+1);
		for(int i=1; i<=4*n; i++) SegmentTree[i] = {0,0};

		for(int i =1; i<= n; i++) cin >> ar[i];
		setUp(1, 1, n);

		while(k--){
			char cmd;
			int x, y;
			cin >> cmd >> x >> y;

			if(cmd=='C'){
				ar[x] = y;
				upDate(1, 1, n, x);
			}else{
				pair<int, int> result = query(1, 1, n, x, y);
				if(result.second) cout << 0;
				else if(result.first%2) cout << '-';
				else cout << '+';
			}

		}
		cout << '\n';

	}

	return 0;
}
