// 20220331 BOJ 좌표 정렬하기 2
// 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	int N, x, y;
	vector<pair<int, int>> cor;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		cor.push_back(make_pair(y, x));
	}

	sort(cor.begin(), cor.end());
	
	for (int i = 0; i < N; i++) {
		cout << cor[i].second << " " << cor[i].first << "\n";
	}
	
	return 0;
}