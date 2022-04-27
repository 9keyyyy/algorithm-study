//20220427
//DP
using namespace std;
#include <iostream>

int cache[1001][10];
int N;
int returnNum() {
	for (int i = 0; i < 10; i++) cache[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				cache[i][j] += cache[i - 1][k] % 10007;
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res += cache[N][i];
	}
	return res % 10007;
}
int main() {
	cin >> N;
	cout << returnNum();
	return 0;
}