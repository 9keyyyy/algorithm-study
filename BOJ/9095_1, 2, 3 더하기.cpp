/*
	22.01.24 BOJ 9095 1, 2, 3 더하기
	동적 계획법

	정수를 1, 2, 3을 더해 나타내야 하므로, 
	n-1의 방법들에 1을 더하여 n을 만들고
	n-2의 방법들에 2를 더하여 n을 만들고
	n-3의 방법들에 3을 더하여 n을 만들면 됨
*/
#include <iostream>
#include <cstring>
using namespace std;

int cache[11];
int findCase(int n) {
	// basecase
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;

	int& ret = cache[n];
	if (ret != -1) return ret;
	
	cache[n] = findCase(n-1) + findCase(n-2) + findCase(n-3);
	return ret;
}
int main() {
	int n, m;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> m;
		cout << findCase(m) << endl;
	}
	
	return 0;
}