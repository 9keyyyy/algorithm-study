#include <iostream>
using namespace std;

int n, m;
double cache[1000][2001];
double climb(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;
	double &ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = 0.25*climb(days + 1, climbed + 1) + 0.75*climb(days + 1, climbed + 2);
}