// 2022-02-07 BOJ 11047 동전 0
// 탐욕법
#include <iostream>
using namespace std;

int N, K;
int value[10];

int calculateMin() {
	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K < value[i]) continue;
		sum += K / value[i];
		K %= value[i];
		if (K == 0) break;
	}
	return sum;
}

int main() {
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) cin >> value[i];
	cout << calculateMin();

	return 0;
}