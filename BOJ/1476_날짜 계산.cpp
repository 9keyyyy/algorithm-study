// 20220210 BOJ 1476 날짜계산
// 완전 탐색
#include <iostream>
using namespace std;

int E, S, M;

// ver1
int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int calculate() {
	int sumE = E, sumS = S, sumSE = 0, sumM = M;
	while (sumE != sumS) {
		if (sumE < sumS) sumE += 15;
		else sumS += 28;
	};
	sumSE = sumE;
	int SE = lcm(15, 28);
	while (sumSE != sumM) {
		if (sumM < sumSE) sumM += 19;
		else sumSE += SE;
	}
	return sumSE;
}

// ver2
int calculate2() {
	int year = 1;
	while (1) {
		if (year % 15 == E && year % 28 == S && year % 19 == M) break;
		else year++;
	}
	return year;
}
int main() {
	cin >> E >> S >> M;
	cout << calculate();
	return 0;
}