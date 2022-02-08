//2022-02-08 BOJ 11728
// STL
// 분할정복
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M, n;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N + M; i++) cout << arr[i] << " ";
	return 0;
}