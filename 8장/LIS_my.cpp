#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >

	1. 정해진 수열의 인덱스를 기준으로 한 가장 긴 부분수열의 길이 구하기
		재귀 호출을 통해 다음 수가 현재 수보다 큰 경우와 그렇지 않은 경우 중 
		더 큰 값을 반환하는 형식으로 MaxLength 함수 구현
	2. 수열을 순회하며 가장 긴 부분 수열 길이를 가진 값 찾아 출력

	memorization : 현재 인덱스의 max값 캐시에 저장

	28ms

-------------------------------------------------------------------------------------------*/
int cache[500];
int seq[500];
// n 인덱스를 기준으로 가장 긴 부분 수열의 길이 구하는 함수
int MaxLength(int n, int next, int size) {
	// base case
	if (next == size) return 1;
	int &ret = cache[n];
	if (ret != -1) return ret;
	int tmp = 0;
	// 다음 수가 현재 수보다 큰 경우
	if (seq[n] < seq[next]) tmp = 1 + MaxLength(next, next + 1, size);
	// result
	return ret = max(tmp, MaxLength(n, next + 1, size));
}
// 전체 수열에서 가장 긴 부분 수열의 길이 찾는 함수
int FindMax(int size) {
	int Max = 0;
	for (int i = 0; i < size; i++) {
		int tmp = MaxLength(i, i + 1, size);
		if (tmp > Max) Max = tmp;
	}
	return Max;
}
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> m;
		for (int j = 0; j < m; j++) cin >> seq[j];
		cout << FindMax(m) << endl;
	}
	return 0;
}