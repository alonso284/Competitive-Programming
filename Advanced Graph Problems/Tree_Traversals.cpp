// Code by $%U%$ $%Y%$
#include <iostream>
#include <complex>
#include <bitset>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

vector<int> preorder;
vector<int> inorder;

vector<int> preorder_idx;
vector<int> inorder_idx;

void dfs(int l, int r, int d){
	const int &root = preorder[l];

	if(l+1 <= inorder_idx[root]+d)
		dfs(l+1, inorder_idx[root]+d, d+1);

	if(inorder_idx[root]+1+d <= r)
		dfs(inorder_idx[root]+1+d, r, d);

	cout << root << ' ';
}

int main(){
	int n; cin >> n;

	preorder.resize(n);
	inorder.resize(n);
	preorder_idx.resize(n+1);
	inorder_idx.resize(n+1);

	for(int &it: preorder) cin >> it;
	for(int &it: inorder) cin >> it;

	for(int i = 0; i < n; i++) preorder_idx[preorder[i]] = i;
	for(int i = 0; i < n; i++) inorder_idx[inorder[i]] = i;

	dfs(0, n-1, 0);
}
