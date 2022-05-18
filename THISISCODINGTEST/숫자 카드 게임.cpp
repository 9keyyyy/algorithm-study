// 20220518
// Greedy
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
vector<int> arr;

int main() {
	int e;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int min = 10000;
		for (int j = 0; j < M; j++) {
			cin >> e;
			if (e < min) min = e;
		}
		arr.push_back(min);
	}
	sort(arr.begin(), arr.end());
	cout << arr[N - 1];
}