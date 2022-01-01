#include <iostream>

#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <cctype>
#include <cmath>
#include <ctgmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>

using namespace std;
// g++ file1.cpp -std=c++11

priority_queue < pair <int, pair <int, int> > > pinturas;
int canva[1000001], N,Q;
vector < pair <int, pair <int, int> > > pos[1000001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= Q; ++i)
    {
        int ini, fin, color;
        cin >> ini >> fin >> color;
        pos[ini].push_back(make_pair(i, make_pair(fin, color)));
    }

    for (int i = 1; i <= N; ++i)
    {
        for(auto& it: pos[i]) pinturas.push(it);
        while(!pinturas.empty() && pinturas.top().second.first < i) pinturas.pop();

        if(pinturas.empty()) continue;
        else canva[i] = pinturas.top().second.second;
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << canva[i] << ' ';
    }

    return 0;
}