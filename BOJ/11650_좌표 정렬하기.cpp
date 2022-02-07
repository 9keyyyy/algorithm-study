// 2022-02-08
// STL sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, x, y;
	vector<pair<int, int>> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}
	// sort 사용할 경우 1번째 원소가 같을 때는 알아서 2번째 원소가 작은 순으로 정렬
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
	return 0;
}