// 20220518
// DP
using namespace std;
#include <iostream>

int N;
int cache[31] = { 0 };

int sol() {
	if (N % 2 == 1) return 0;
	
	cache[2] = 3;
	for (int i = 3; i <= N; i++) {
		if (N % 2 == 1) continue;
		cache[i] = cache[i - 2] * 3;
		for (int j = i - 4; j > 0; j -= 2) {
			cache[i] += cache[j] * 2;
		}
		cache[i] += 2;
	}

	return cache[N];
}

int main() {
	cin >> N;
	cout << sol();
	return 0;
}