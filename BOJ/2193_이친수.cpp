//20220428
//DP
using namespace std;
#include <iostream>

long long cache[91][2];
int n;

long long returnPinary() {
	cache[1][0] = 0;
	cache[1][1] = 1;
	cache[2][0] = 1;
	cache[2][1] = 0;
	
	for (int i = 3; i <= n; i++) {
		cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
		cache[i][1] = cache[i - 1][0];
	}

	return cache[n][0] + cache[n][1];

}

int main() {

	cin >> n;
	cout << returnPinary();


	return 0;
}