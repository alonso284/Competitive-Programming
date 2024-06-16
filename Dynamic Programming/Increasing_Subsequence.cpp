#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

struct FenwickTreeMax {
    vector<int> bit;
    int n;
    const int INF = (int)0;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmax(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

int main(){

	int n;
	cin >> n;
	vector<int> x(n), t(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
		t[i] = x[i];
	}

	sort(t.begin(), t.end());
	int s = 1;
	map<int, int> comp;
	for(int i = 0; i < n; i++)
		if(!comp.count(t[i])) comp[t[i]] = s++;
	for(int i = 0; i < n; i++)
		x[i] = comp[x[i]];

	FenwickTreeMax ft(s+1);

	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		int temp = ft.getmax(s-x[i]-1) + 1;
		ans = max(ans, temp);
		ft.update(s-x[i], temp);
	}

	cout << ans << endl;



	return  0;
}
