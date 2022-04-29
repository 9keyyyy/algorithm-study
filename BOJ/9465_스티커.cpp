//20220429
//DP
using namespace std;
#include <iostream>
#include <string.h>
#include <math.h>
int T, n;
int arr[2][100001];
int dp[2][100001]; //a번째 줄의 b번째 스티커 선택 시 최대값

int returnMax() {
	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}
	return max(dp[0][n], dp[1][n]);

}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> arr[j][k];
			}
		}
		cout << returnMax() << '\n';
	}
	return 0;
}