// 20220509
// DP
using namespace std;
#include <iostream>
#include <math.h>
int stair[301] = { 0 };
int cache[301] = { 0 };
int N;

int sol() {
	cache[0] = stair[0];
	cache[1] = stair[0] + stair[1];
	cache[2] = max(stair[2] + stair[0], stair[2] + stair[1]);
	for (int i = 3; i < N; i++) {
		cache[i] = max(cache[i - 2] + stair[i], cache[i - 3] + stair[i - 1] + stair[i]);
	}
	return cache[N - 1];
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> stair[i];
	cout << sol();
	return 0;
}