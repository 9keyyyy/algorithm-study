// 동적 계획법
// 888ms
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int cache[2][100][100][100];
int arrN[100];
int arrM[100];
int N, M, C;

int LIS(int cur, int curN, int curM, int flag) {
	// memorization
	int& ret = cache[flag][cur][curN][curM];
	if (ret != -1) return ret;

	if (!flag) {
		for (int i = cur; i < N; i++) {
			if (arrN[cur] < arrN[i]) {
				ret = max(ret, LIS(i, i, curM, 0) + 1);
			}
		}
		for (int i = curM; i < M; i++) {
			if (arrN[cur] < arrM[i]) {
				ret = max(ret, LIS(i, curN, i, 1) + 1);
			}
		}
	}
	else {
		for (int i = curN; i < N; i++) {
			if (arrM[cur] < arrN[i]) {
				ret = max(ret, LIS(i , i, curM, 0) + 1);
			}
		}
		for (int i = cur; i < M; i++) {
			if (arrM[cur] < arrM[i]) {
				ret = max(ret, LIS(i , curN, i, 1) + 1);
			}
		}
	}
	
	if (ret == -1) ret = 1;
	return ret;
}


int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		memset(cache, -1, sizeof(cache));
		for (int j = 0; j < N; j++) cin >> arrN[j];
		for (int j = 0; j < M; j++) cin >> arrM[j];

		int m = LIS(0, 0, 0, 0);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int tmp = max(LIS(j, j, k, 0), LIS(k, j, k, 1));
				if (m < tmp) m = tmp;
				
			}
		}
		cout << m << endl;
	}
}