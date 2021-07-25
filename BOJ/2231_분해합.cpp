// ¿ÏÀü Å½»ö
// 4ms
#include <iostream>
using namespace std;

int main() {
	int N, min = 0;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n, sum;
		n = sum = i;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		if (sum == N) {
			min = i;
			break;
		}
	}
	cout << min;
}