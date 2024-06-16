// Alonso Huerta Escalante
// Link https://cses.fi/problemset/task/1734

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <functional>
#include <random>
#include <cstring>
#include <climits>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int x[200005];
int frq[200005], diff = 0;
int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

void remove(int idx){  // TODO: remove value at idx from data structure
	frq[x[idx]]--;
	if(frq[x[idx]] == 0) diff--;
}
void add(int idx){     // TODO: add value at idx from data structure
	frq[x[idx]]++;
	if(frq[x[idx]] == 1) diff++;
}
int get_answer(){  // TODO: extract the current answer of the data structure
	return diff;
}

vector<int> mo_s_algorithm(vector<Query> &queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query &q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main(){
	IOS;

	int n, q;
	cin >> n >> q;
	vector<Query> queries(q);
	for(int i = 0; i < n; i++) cin >> x[i];
	// amp values to smaller sizes
	int cur = 1;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		if(mp.find(x[i]) == mp.end()) mp[x[i]] = cur++;
		x[i] = mp[x[i]];
	}

	for(int i = 0; i < q; i++){
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].idx = i;
	}

	block_size = sqrt(n);

	vector<int> answers = mo_s_algorithm(queries);
	for(int i = 0; i < q; i++) cout << answers[i] << "\n";

	return 0;
}
