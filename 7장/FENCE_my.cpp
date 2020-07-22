#include <iostream>
#include <algorithm>
using namespace std;

/*---------------------------------------------------------------------------------------------

	<	전체적인 알고리즘	>
 1. 현재 배열 위치에서 오른쪽으로 진행하면서 막대 크기가 현재 막대보다 작은 경우가 나올때까지 더함
 2. 똑같은 방법으로 왼쪽으로 진행
 3. 현재 구한 넓이 값과 현재 배열에서 index +1 한 함수의 넓이 값 비교해서 큰 값으로 결정

----------------------------------------------------------------------------------------------*/
int MaxSize(int *N, int size, int cur) {	// size : 입력받은 사이즈, cur : 현재 위치
	int *p, area = 0;
	// base case : 입력받은 size만큼 함수가 다 돌았을 때
	if (size == cur) return 0;
	for (p = N; p < N+size-cur; p++) {	// 배열의 오른쪽 끝까지 진행
		if (*p >= *N) area += *N;
		else break;
	}
	if (cur != 0) {
		for (p = N-1; p >= N - cur; p--) {	// 배열의 왼쪽 끝까지 진행
			if (*p >= *N) area += *N;
			else break;
		}
	}
	return max(area, MaxSize(++N, size, ++cur));	// 크기 비교
}
int main() {
	int N[20000], n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++)
			cin >> N[j];
		int area = MaxSize(N, m, 0);
		cout << area << endl;
	}
	return 0;
}