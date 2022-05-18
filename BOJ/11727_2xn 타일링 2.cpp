//20220425
//DP
using namespace std;
#include <iostream>

int n;
int cache[1001] = { 0 };

int returnRec(int here) {
	int& ret = cache[here];
	
	if (here <= 2 || ret != 0) return ret;
	
	ret = (returnRec(here - 1) + 2 * returnRec(here - 2)) % 10007;
	return ret;
}

int main() {
	cache[1] = 1;
	cache[2] = 3;

	cin >> n;
	cout << returnRec(n);
	return 0;
}