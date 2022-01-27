// 22.01.28 BOJ 11726 2xn 타일링
// 동적 계획법
#include <iostream>
#include <cstring>
using namespace std;

int cache[1001];
int tiling(int n) {
	// basecase
	if (n <= 2) return n;

	int& ret = cache[n];
	if (ret != -1) return ret;

	return ret = (tiling(n - 1) + tiling(n - 2)) % 10007;
}
int main() {
	int n;

	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << tiling(n) ;

	return 0;
}