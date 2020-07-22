#include <iostream>
#include <algorithm>
using namespace std;

int MaxSize(int *N, int size, int cur) {
	int *p, area = 0;
	if (size == cur) return 0;
	for (p = N; p < N+size-cur; p++) {
		if (*p >= *N) area += *N;
		else break;
	}
	if (cur != 0) {
		for (p = N-1; p >= N - cur; p--) {
			if (*p >= *N) area += *N;
			else break;
		}
	}
	cout << "["<<area<<"]";
	return max(area, MaxSize(++N, size, ++cur));
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