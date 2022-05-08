// 20220508
// DP
using namespace std;
#include <iostream>

int cache[1001];
int arr[1001];
int N;

int returnMaxSeq(int idx) {
	
	if (idx == N - 1) return arr[idx];
	int& ret = cache[idx];
	if (ret != 0) return ret;
	
	int res, max = arr[idx];
	for (int i = idx + 1; i < N; i++) {
		if (arr[idx] < arr[i]) {
			res = arr[idx] + returnMaxSeq(i);
			if (res > max) max = res;
		}
	}
	return ret = max;
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> arr[i];

	int res,max = 0;
	for (int i = 0; i < N; i++) {
		res = returnMaxSeq(i);
		if (res > max) max = res;
	}
	cout << max;
	return 0;
}