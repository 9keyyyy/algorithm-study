// 20220221 BOJ 2042 구간 합 구하기
// 펜윅 트리
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

long long arr[1000001], tree[1000001];
int n, m, k;

// i번째 수까지의 합 구하는 함수
long long prefixSum(int i) {
	long long result = 0;
	while (i > 0) {
		result += tree[i];
		// 0이아닌 마지막 비트(i & -i)만큼 빼가면서 이동 
		i -= (i & -i);
	}
	return result;
}

// i번째 수에 dif 만큼 더하는 함수
void update(int i, long long dif) {
	while (i <= n) {
		tree[i] += dif;
		i += (i & -i);
	}
}

// start부터 end까지의 구간 합 계산
long long intervalSum(int start, int end) {
	return prefixSum(end) - prefixSum(start - 1);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		long long x;
		scanf("%lld", &x);
		arr[i] = x;
		update(i, x);
	}
	int count = 0;
	while (count++ < m + k) {
		int op;
		scanf("%d", &op);
		// 업데이트 연산일 경우
		if (op == 1) {
			int index;
			long long value;
			scanf("%d %lld", &index, &value);
			update(index, value - arr[index]); // 바뀐 크기만큼 적용
			arr[index] = value;
		}
		// 구간 합 연산일 경우
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", intervalSum(start, end));
		}
	}
	return 0;
}