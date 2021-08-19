// 분할 정복
// 140ms
#include <iostream>
#include <math.h>
using namespace std;
int C, N;
int fence[20001];

// ver1. 시간초과
int fenceMax_timeout(int s, int e) {
	// basecase
	if (s == e) return fence[s];

	int mid = (e + s) / 2;
	int res = max(fenceMax_timeout(s, mid), fenceMax_timeout(mid + 1, e));
	
	int smaller = min(fence[mid], fence[mid + 1]);
	for (int height = 1; height <= smaller; height++) {
		int sum = 0;
		for (int cur = mid; cur >= s; cur--) {
			
			if (fence[cur] >= height) sum += height;
			else break;
		}	
		for (int cur = mid + 1; cur <= e; cur++) {
			
			if (fence[cur] >= height) sum += height;
			else break;
		}		
		if (sum > res) res = sum;
	}
	return res;
}
// ver2.
int fenceMax(int s, int e) {
	// basecase
	if (s == e) return fence[s];

	int mid = (e + s) / 2;
	int res = max(fenceMax(s, mid), fenceMax(mid + 1, e));

	int H = min(fence[mid], fence[mid + 1]);
	int L = mid, R = mid + 1;
	res = max(res, H * (R - L + 1));
	while (s < L && e > R) {
		if (fence[L - 1] < fence[R + 1]) {
			H = min(H, fence[R + 1]);
			R++;
		}
		else {
			H = min(H, fence[L - 1]);
			L--;
		}
		res = max(res, H * (R - L + 1));
	}
	while (s < L) {
		H = min(H, fence[L - 1]);
		L--;
		res = max(res, H * (R - L + 1));
	}
	while (e > R) {
		H = min(H, fence[R + 1]);
		R++;
		res = max(res, H * (R - L + 1));
	}
	return res;
}

int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) cin >> fence[j];
		cout << fenceMax(0, N - 1) << endl;
	}
}