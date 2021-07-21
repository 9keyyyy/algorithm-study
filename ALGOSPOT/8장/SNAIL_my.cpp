#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*-----------------------------------------------------------------

		< 내가 생각한 알고리즘 >

	n : 전체날짜 , r : 비온날짜
	0.75^r X 0.25^(n-r) X nCr
	memorization 적용 안함..

	factorial 수가 너무 커지는 경우 때문에 런타임에러남..

-----------------------------------------------------------------*/
int cache[1000];
int fac(int n) {
	int sum = 1;
	while (n > 1) {
		sum *= n;
		n--;
	}
	return sum;
}
double snail(int depth, int rain) {
	double go = 0;
	for (int i = 0; i <= rain; i++) {
		if (i * 2 + (rain - i) >= depth) {
			int combination = fac(rain) / (fac(i)*fac(rain - i));
			go += pow(0.75, i)*pow(0.25, rain - i)*combination;
		}
	}
	return go;
}
int main() {
	int n, depth, rain;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> depth >> rain;
		printf("%.10lf\n", snail(depth, rain));
	}
	return 0;
}
