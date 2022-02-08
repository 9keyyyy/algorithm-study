//2022-02-08 BOJ 11728
// 분할정복
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M, n;
vector<int> arr;

// 합병 정렬 구현
void mergesort(int s, int e) {
	if (e <= s) return;
	int pivot = s + (e - s) / 2;
	mergesort(s, pivot);
	mergesort(pivot + 1, e);
	vector<int> tmp;
	int i = s, j = pivot + 1;
	while (i <= pivot && j <= e) {
		if (arr[i] < arr[j]) tmp.push_back(arr[i++]);
		else tmp.push_back(arr[j++]);
	}
	while (i <= pivot) tmp.push_back(arr[i++]);
	while (j <= e) tmp.push_back(arr[j++]);

	for (int k = 0; k < tmp.size(); k++)
		arr[s++] = tmp[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> n;
		arr.push_back(n);
	}
	mergesort(0, N + M - 1);

	for (int i = 0; i < N + M; i++) cout << arr[i] << " ";
	return 0;
}