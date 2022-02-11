// 20220212
// 이분 탐색(Binary Search) -> 정렬되어 있는 경우에만 사용 가능
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 입출력 속도를 빠르게 하기 위해 사용
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	int N, M, num;
	vector<int> A;
	vector<int> arr;
	vector<int>::iterator it;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}
	sort(A.begin(), A.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		/* ver1. 시간 초과
		it = find(A.begin(), A.end(), num);
		if (it != A.end()) cout << "1\n";
		else cout << "0\n";
		*/
		// ver.2
		if(binary_search(A.begin(), A.end(), num)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}