// 동적 계획법
// 24ms
#include <iostream>
#include <string.h>
using namespace std;

int cache[500];
int arr[500];
int C, N;

int LIS(int cur) {
	// memorization
	int& ret = cache[cur];
	if (ret != -1) return ret;

	// basecase
	if (cur == N - 1) return ret = 1;

	for (int i = cur; i < N; i++) {
		if (arr[cur] < arr[i]) {
			ret = max(ret, LIS(i) + 1);
		}
	}
	if (ret == -1) ret = 1;
	return ret;
}

int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> arr[j];

		int max = LIS(0);
		for (int j = 1; j < N; j++) {
			int tmp = LIS(j);
			if (max < tmp) max = tmp;
		}
		cout << max << endl;
	}
}