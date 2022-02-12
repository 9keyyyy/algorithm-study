// 20220212 BOJ 2875 
// 그리디
#include <iostream>
using namespace std;

int main() {
	int N, M, K, sum = 0;
	cin >> N >> M >> K;

	while (N >= 2 && M >= 1) {
		N -= 2;
		M -= 1;
		if (N + M >= K) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}