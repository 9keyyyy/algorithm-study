// 완전 탐색
// 1736ms
#include <iostream>
#include <string.h>
using namespace std;

int Switch[10][16] = {
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
int Clock[16];

// 모든 시계의 시간이 12시인지 확인하는 함수
int isAllTwelve() {
	for (int i = 0; i < 16; i++) {
		if (Clock[i] != 12) return 0;
	}
	return 1;
}

int findtwelve(int n, int ret) {
	// basecase
	if (isAllTwelve()) return ret;
	if (n == 10) return -1;			// 스위치는 10번까지만 있음

	// 한 스위치 당 0-3번 누르는 경우 있음
	for (int num = 0; num < 4; num++) {
		for (int j = 0; j < 16; j++) {
			Clock[j] += 3 * Switch[n][j] * num;
			if (Clock[j] > 12) Clock[j] -= 12;
		}

		int res = findtwelve(n + 1, ret + num);
		if (res != -1) return res;

		for (int j = 0; j < 16; j++) {
			Clock[j] -= 3 * Switch[n][j] * num;
			if (Clock[j] < 3) Clock[j] += 12;
		}
	}
	return -1;
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < 16; j++) cin >> Clock[j];
		cout << findtwelve(0, 0) << endl;
	}
}