//20220420
//DP
using namespace std;
#include <iostream>

int N, arr[100000], cache[100000];

int main() {
	
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	int max = arr[0];
	for (int i = 0; i < N; i++) {
		cache[i] = arr[i];
		if (i == 0) continue;
		if (cache[i] < cache[i - 1] + arr[i])
			cache[i] = cache[i - 1] + arr[i];
		if (cache[i] > max) max = cache[i];
	}
	cout << max;

	return 0;
}