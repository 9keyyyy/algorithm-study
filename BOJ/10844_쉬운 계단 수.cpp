//20220426
//DP
using namespace std;
#include <iostream>

int cache[101][11] = { 0 };
int N;

long long returnStair() {
	for (int i = 1; i < 10; i++) cache[1][i] = 1;
	cache[1][0] = 0;
	
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) cache[i][j] = cache[i - 1][j + 1] % 1000000000;
			else if (j == 9) cache[i][j] = cache[i - 1][j - 1] % 1000000000;
			else cache[i][j] = (cache[i - 1][j + 1] + cache[i - 1][j - 1]) % 1000000000;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += cache[N][i];

	return ans;
}

int main() {
	
	cin >> N;
	cout << returnStair() % 1000000000;

	return 0;
}