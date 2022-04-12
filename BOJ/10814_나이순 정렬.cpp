//20220413 BOJ 10814 나이순 정렬
//stable sort
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int N, y;
	string n;
	vector<pair<int, string>> arr;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> y >> n;
		arr.push_back(make_pair(y, n));
	}
	stable_sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << arr[i].first << ' ' << arr[i].second << "\n";
	}
}