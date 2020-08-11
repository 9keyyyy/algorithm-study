#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
/*-------------------------------------------------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >

	C++ STL queue 이용
	queue에 수열 합이 K 미만이 되도록 부분수열 저장
	수열 합이 K 이상일 때
	1. 수열 합이 K보다 클 때: queue 원소를 pop해서 합이 K 보다 작게 만들고, 그 과정에서 합이 K가 되는 경우 total 값 +1
	2. 수열 합이 K일 때: total 값 +1 하고, 위와 같이 queue 원소를 pop해서 합이 K보다 작아지도록 만듬

	난수 생성에서 오류 발생 (pow 적용X) ---> 식 그대로 넣으면 안되고 난수 생성 툴 따로 만들어야함,,,

	4140ms

--------------------------------------------------------------------------------------------------------------------------------------*/
// int A[50000000];
struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};
int SumK(int n, int K) {
	int sum = 0, total = 0;
	queue<int> q;
	RNG rng;
	for (int i = 0; i < n; i++) {
		//sum += A[i];
		//q.push(A[i]);
		int A = rng.next();
		sum += A;
		q.push(A);
		if (sum >= K) {
			if (sum == K) total += 1;
			while (sum >= K) {
				sum -= q.front();
				q.pop();
				if (sum == K) total += 1;
			}
		}
	}
	return total;
}
int main() {
	int n, K, N, a = pow(2, 32);
//	A[0] = 1983;
//	for (int i = 1; i < 50000000; i++)
//		A[i] = (A[i - 1] * 214013 + 2531011) % a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> K >> N;
		cout << SumK(N, K) << endl;

	}
	return 0;
}