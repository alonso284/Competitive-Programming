// Code by $%U%$ $%Y%$
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

void solve();

int main(){
	int tt = 1;
	while(tt--)
		solve();

	return 0;
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	vector<set<int>> row(n), column(n);

	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	{
		set<int> mex;
		mex.insert(row[i].begin(), row[i].end());
		mex.insert(column[j].begin(), column[j].end());
		int MEX = 0;
		for(const int &it: mex)
			if(MEX == it) MEX++;
			else break;
		row[i].insert(MEX);
		column[j].insert(MEX);
		grid[i][j] = MEX;
	}

	for(const vector<int> &row: grid){
		for(const int &cell: row)
			cout << cell << ' ';
		cout << endl;
	}
}
