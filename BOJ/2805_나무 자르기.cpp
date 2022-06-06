// 20220606
// 분할 정복
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long N, M;
vector<long long> arr;
long long res = 0;

void biSearch(long long s, long long e) {
	if (s >= e) return;
	long long mid = (s + e) / 2;
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		long long tree = arr[i] - mid;
		if (tree > 0) cnt += tree;
	}

	if (cnt >= M) {
		biSearch(mid + 1, e);
		res = max(res, mid);
	}
	else biSearch(s, mid);

}

int main() {
	long long e;
	cin >> N >> M;
	long long m_len = 0;
	for (int i = 0; i < N; i++) {
		cin >> e;
		arr.push_back(e);
		m_len = max(m_len, e);
	}
	biSearch(1, m_len);
	cout << res;
	return 0;
}