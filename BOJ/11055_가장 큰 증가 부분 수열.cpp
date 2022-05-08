// 20220508
// DP
using namespace std;
#include <iostream>
#include <math.h>
int cache[1001];
int arr[1001];
int N;

// ver1. recur
// 배열의 끝에서부터 생각
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

// ver2. non-recur
// 배열의 시작에서부터 생각
int sol() {
	int m;
	for (int i = 0; i < N; i++) {
		cache[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cache[i] = max(cache[j] + arr[i], cache[i]);
			}
		}
		m = max(m, cache[i]);
	}
	return m;
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