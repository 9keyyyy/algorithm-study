// 20220508
// DP
using namespace std;
#include <iostream>
#include <math.h>
int cache[1001];
int arr[1001];
int N;

int sol() {
	int m = 0;
	for (int i = 0; i < N; i++) {
		cache[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				cache[i] = max(cache[j] + 1, cache[i]);
			}
		}
		m = max(m, cache[i]);
	}
	return m;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << sol();
	return 0;
}