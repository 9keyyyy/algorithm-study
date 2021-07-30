// 동적 계획법
// 0ms
#include <iostream>
#include <string.h>
using namespace std;

int cache[5001];

int findMin(int n) {
	// cache 사용
	int& ret = cache[n];
	if (ret != 0) return ret;
	
	// basecase
	if (n == 0) return ret = 0;
	if (n < 0) return ret = -1;

	int three = findMin(n - 3);
	int five = findMin(n - 5);
	if (three == -1 && five == -1) return ret = -1;				
	if (three == -1 || five == -1) return max(three, five) + 1;	
	return ret = min(three, five) + 1;							
}

int main() {
	int N;
	memset(cache, 0, sizeof(cache));
	cin >> N;
	cout << findMin(N);
}