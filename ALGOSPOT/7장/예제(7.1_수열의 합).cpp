
/*
분할 정복 예제 - 수열의 합 구하기

fastSum(n)

= 1+2+3+...+n

= (1+2+3+..+n/2) + ((n/2+1)+...+n)

= (1+2+3+..+n/2) + (n/2+1) + (n/2+2) + ... + (n/2 + n/2)

= (1+2+3+..+n/2) + n/2 * n/2 + (1+2+...+n/2)

= fastSum(n/2) + n/2 * n/2 + fastSum(n/2)

*/

#include <iostream>
using namespace std;

int fastSum(int n) {
	if (n == 1) return 1;
	if (n % 2 == 1) return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + n / 2 * n / 2;
}