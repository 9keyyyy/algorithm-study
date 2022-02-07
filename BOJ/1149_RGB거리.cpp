// 2022-02-07 BOJ RGB 거리
// 동적계획법
#include <iostream>
#include <math.h>
using namespace std;

int N, cache[1000][3], RGB[1000][3];
int calculateMin() {
	for (int i = 0; i < 3; i++) cache[0][i] = RGB[0][i];

	for (int idx = 1; idx < N; idx++) {
		for (int i = 0; i < 3; i++) {
			int min = 1000000;
			for (int j = 0; j < 3; j++) {
				if (i != j) {
					if (min > RGB[idx][i] + cache[idx - 1][j]) min = RGB[idx][i] + cache[idx - 1][j];
				}
			}
			cache[idx][i] = min;
		}
	}

	int min = cache[N-1][0];
	for (int i = 1 ; i < 3; i++)
		if (min > cache[N-1][i]) min = cache[N-1][i];
	return min;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	cout << calculateMin();
	return 0;
}