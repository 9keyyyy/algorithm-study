//20220419
//DP
using namespace std;
#include <iostream>
#include <vector>

int N, arr[1000], cache[1000] = { 0 };

int returnSeq(int cur) {
	if (cur == N - 1) return 0;
	int& ret = cache[cur];
	if (ret != 0) return ret;

	for (int i = cur + 1; i < N; i++) {
		if (arr[cur] < arr[i]) {
			int res = 1 + returnSeq(i);
			if (ret < res) ret = res;
		}
	}
	return ret;

}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		int res = returnSeq(i);
		if (max < res) max = res;
	}

	cout << max + 1;
	return 0;
}