// Alonso Huerta Escalante
// https://cses.fi/problemset/task/1144/

#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, q;
int ar[200005];
vector< pair<char, pair<int, int> > > queries;
map<int, int> newValues;
set<int> usedValues = {-1, 0, (int)1e9+1};

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> ar[i];
		usedValues.insert(ar[i]);
	}

	while(q--){
		char command; int a, b;
		cin >> command >> a >> b;
		
		switch(command){
			case '!':
				usedValues.insert(b);
				break;
		}

		queries.push_back(make_pair(command, make_pair(a, b)));
	}

	for(auto& q:queries){
		if(q.first == '?'){
			auto ita = usedValues.lower_bound(q.second.first); ita--;
			q.second.first = *ita;

			auto itb = usedValues.upper_bound(q.second.second); itb--;
			q.second.second = *itb;
		}
	}

	int p = 0;
	for(const int &it: usedValues)
		newValues[it] = p++;

	FenwickTree ft(p);
	for(int i = 1; i <= n; i++)
		ft.add(newValues[ar[i]], +1);

	for(const auto& q:queries){
		switch(q.first){
			case '?':
				cout << ft.sum(newValues[q.second.second]) - ft.sum(newValues[q.second.first]) << '\n';
				break;
			case '!':
				ft.add(newValues[ar[q.second.first]], -1);
				ar[q.second.first] = q.second.second;
				ft.add(newValues[ar[q.second.first]], +1);
				break;
		}
	}
	cout << endl;
		
	return 0;
}
