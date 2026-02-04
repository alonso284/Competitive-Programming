// Code by $%U%$ $%Y%$
#include <iostream>
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

vector<int> parent;
vector<int> SIZE;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    SIZE[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (SIZE[a] < SIZE[b])
            swap(a, b);
        parent[b] = a;
        SIZE[a] += SIZE[b];
    }
}

int main(){
	int n; cin >> n;
	int m; cin >> m;
	parent.resize(n+1);
	SIZE.resize(n+1);

	int MAX = 1;
	int comp = n;
	for(int v = 1; v <= n; v++)
		make_set(v);

	while(m--){
		int a, b; cin >> a >> b;
		if(find_set(a) != find_set(b))
			comp--;
		
		union_sets(a, b);

		MAX = max(MAX, SIZE[find_set(a)]);

		cout << comp << ' ' << MAX << endl;

	}
}
