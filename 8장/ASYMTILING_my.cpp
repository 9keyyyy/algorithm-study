#include <iostream>
#include <cstring>
using namespace std;
/*----------------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >

	TILING2 문제에서 대칭이 되는 방법의 개수를 뺌 (함수는 sol 그대로 사용하고 메인에서 처리함)
	n이 짝수일때 : (전체 방법수) - (n/2 사각형 방법수) - (n/2-1 사각형 방법수)
	n이 홀수일때 : (전체 방법수) - (n/2 사각형 방법수)

	전체 방법의 수는 1000000007의 나머지 값으로 출력하기 때문에, 
	값이 음수가 되는 경우 1000000007를 더해주면됨

	0ms

-----------------------------------------------------------------------------------------------------*/
const int MOD = 1000000007;
int cache[101];
int s;

int tiling(int width) {
	if (width <= 1) return 1;
	int &ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> s;

		if (s % 2 == 0) {
			int a = tiling(s) - tiling(s / 2) - tiling(s / 2 - 1);
			while (a < 0) a += MOD;
			cout << a << endl;
		}
		else {
			int a = tiling(s) - tiling(s / 2);
			if (a < 0) a += MOD;
			cout << a << endl;
		}
	}
	return 0;
}
