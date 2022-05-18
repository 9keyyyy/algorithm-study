// 20220518
// greedy
using namespace std;
#include <iostream>

int N, K, cnt = 0;
int main() {
	cin >> N >> K;
	while (N!=1) {
		if (N % K == 0) N /= K;
		else N -= 1;
		cnt++;
	}
	cout << cnt;
	return 0;
}