//2022-02-08 BOJ 11728
// 분할정복
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M, n;
int a[1000000];
int b[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}

	int idxA = 0, idxB = 0;
	while (idxA < N && idxB < M) {
		if (a[idxA] < b[idxB]) cout << a[idxA++] << " ";
		else cout << b[idxB++] << " ";
	}
	while (idxA < N) cout << a[idxA++] << " ";
	while (idxB < M) cout << b[idxB++] << " ";
	return 0;
}