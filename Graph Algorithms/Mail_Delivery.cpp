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

int main() {
    int n; cin >> n;
	int m; cin >> m;

    vector<int> deg(n);
	vector<set<int>> adj(n);
	while(m--){
		int a, b; cin >> a >> b; a--, b--;
		adj[a].insert(b);
		adj[b].insert(a);
		deg[a]++, deg[b]++;
	}

	// Every degree has to be even
    for (int i = 0; i < n; ++i) 
        if (deg[i] & 1){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}

    stack<int> st;
    st.push(0);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();

        if (adj[v].empty()) {
            res.push_back(v);
            st.pop();
        } else {
        	int i = *adj[v].begin();
			adj[v].erase(i);
			adj[i].erase(v);
            st.push(i);
        }
    }

    for(int i = 0; i < n; ++i) 
        if(!adj[i].empty()) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
        }

	for (int x : res)
		cout << x+1 << " ";
}
