// 20220508
// DP
using namespace std;
#include <iostream>
#include <math.h>

int arr[1001];
int cache_In[1001];
int cache_De[1001];
int N;
int sol() {
	for (int i = 0; i < N; i++) {
		cache_In[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cache_In[i] = max(cache_In[i], cache_In[j] + 1);
			}
		}

	}
	for (int i = N - 1; i >= 0; i--) {
		cache_De[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				cache_De[i] = max(cache_De[i], cache_De[j] + 1);
			}
		}
	}
	int res, max = 0;
	for (int i = 0; i < N; i++) {
		res = cache_In[i] + cache_De[i] - 1;
		if (max < res) max = res;
	}
	return max;
}
int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << sol();

	return 0;
}