#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int N; cin >> N;
	long long arr[N], left[N], right[N];
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		left[i] = right[i] = 0;
	}

	// find the first lower to the left
	// find the first lower to the right
	stack<int> s;

	for (int i = 0; i < N; i++){
		while (!s.empty() && arr[s.top()] >= arr[i]){
			s.pop();
		}
		if (s.empty()){
			left[i] = -1;
		} else {
			left[i] = s.top();
		}
		s.push(i);
	}

	while (!s.empty()){
		s.pop();
	}

	for (int i = N-1; i >= 0; i--){
		while (!s.empty() && arr[s.top()] >= arr[i]){
			s.pop();
		}
		if (s.empty()){
			right[i] = N;
		} else {
			right[i] = s.top();
		}
		s.push(i);
	}

	long long res = 0;
	for (int i = 0; i < N; i++)
		res = max(res, arr[i] * (right[i] - left[i] - 1));

	cout << res << endl;



}
