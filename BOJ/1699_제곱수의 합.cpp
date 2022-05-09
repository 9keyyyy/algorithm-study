// 20220509
// DP
using namespace std;
#include <iostream>
#include <math.h>
int N;
int cache[100001];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cache[i] = i;
		for (int j = 1; j * j <= i; j++) {
			cache[i] = min(cache[i], cache[i - j * j] + 1);
		}
	}

	cout << cache[N];

	return 0;
}