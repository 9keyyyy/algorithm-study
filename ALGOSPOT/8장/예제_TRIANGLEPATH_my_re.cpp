// 동적 계획법
// 40ms
#include <iostream>
#include <string.h>
using namespace std;

int triangle[100][100];
int cache[100][100];
int n, C;

int findMax(int y, int x) {
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	// basecase
	if (y == n - 1) return ret = triangle[y][x];
	return ret = max(findMax(y + 1, x), findMax(y + 1, x + 1)) + triangle[y][x];
}

int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> triangle[j][k];
			}
		}
		cout << findMax(0, 0) << endl;
	}
}