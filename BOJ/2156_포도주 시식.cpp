//20220502
//DP
using namespace std;
#include <iostream>
#include <string.h>
int cache[10001];
int arr[10001];
int n;

/*
	cache[n] ?
	1. n번째 잔을 마시는 경우
		- n-1번째 잔을 마신 경우 
			n-1, n번째 잔을 마셨기 때문에 더이상 잔을 더할 수 없음
			cache[n] = cache[n-3] + arr[n-1] + arr[n]	
		- n-1번째 잔을 마시지 않은 경우
			cache[n] = cache[n-2] + arr[n]
	2. n번째 잔을 마시지 않는 경우
		- cache[n-1]
*/
int returnMax() {
	cache[0] = arr[0] = 0;
	cache[1] = arr[1];
	cache[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		cache[i] = max(cache[i - 1], max(cache[i - 3] + arr[i - 1] + arr[i], cache[i - 2] + arr[i]));
	}

	return cache[n];
}
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	cout << returnMax() << "\n";
	//for (int i = 0; i < n; i++) {
	//	cout << cache[i] << " ";
	//}
	return 0;
}