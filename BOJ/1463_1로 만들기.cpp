//20220421
//DP
using namespace std;
#include <iostream>
#include <math.h>
int N, cache[1000001] = { 0 };

int findCnt(int num) {
	if (num == 1) return 0;
	
	int& ret = cache[num];
	if (ret != 0) return ret;

	int res = 1 + findCnt(num - 1);
	if (num % 3 == 0) res = min(res, 1 + findCnt(num / 3));
	if (num % 2 == 0) res = min(res, 1 + findCnt(num / 2));

	ret = res;
	return ret;
}
int main() {
	cin >> N;
	
	cout << findCnt(N);
	return 0;
}