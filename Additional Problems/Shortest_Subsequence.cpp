#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define PY points[indx]

int sp(char c){
	switch(c){
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
		default:
			return -1;
	}
}

int main(){
	string s;
	cin >> s;
	array<int, 4> indxs = {-1, -1, -1, -1};;
	vector<array<int, 4> > points(s.size());
	for(int i = 0; i < s.size(); i++){
		points[i] = indxs;
		indxs[sp(s[i])] = i;
	}
	points.push_back(indxs);

	int indx = s.size();
	string ans;
	while(indx != -1){
		int m = min(min(PY[0], PY[1]), min(PY[2], PY[3]));
		if(PY[0] == m) ans += 'A';
		else if(PY[1] == m) ans += 'C';
		else if(PY[2] == m) ans += 'G';
		else if(PY[3] == m) ans += 'T';
		indx = m;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;

}
