// 20220605
// 이분 탐색
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, K;
vector<long long> arr;
long long res = 0;

void biSearch(long long s, long long e) {
	if (s >= e) return;

	long long mid = (s + e) / 2;
	int cnt = 0;
	for (int i = 0; i < K; i++)
		cnt += arr[i] / mid;

	if (cnt < N) biSearch(s, mid);
	else {
		res = max(res, mid);
		biSearch(mid + 1, e);
	}

}

int main() {
	long long e;
	
	cin >> K >> N;
	long long m_len = 0;
	for (int i = 0; i < K; i++) {
		cin >> e;
		m_len = max(m_len, e);
		arr.push_back(e);
	}
	biSearch(1, m_len + 1);
	cout << res;
	return 0;
}