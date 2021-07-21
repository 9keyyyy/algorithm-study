#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*----------------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >

	memorization 어떻게 적용해야할지 떠오르지 않아서 완전 탐색법 이용
	숫자를 3, 4, 5 자리로 끊는 경우 모두 고려해 가장 작은 난이도로 합산되는 값 출력
		1. 자릿수 1 ~ 2 일 때 - case 별로 다음 자릿수로 넘기는 재귀 함수 호출
		2. 자릿수 3 ~ 4 일 때 - 자릿수 3, 4, 5 일 때 중 가장 작은 난이도 나오는 값 찾음
		3. 자릿수 5 일 때 - 자릿수 0 으로 재귀 함수 호출해 새로운 case 분류하게끔 해줌

	... 시간초과 ...

-----------------------------------------------------------------------------------------------------*/
//int cache[10000];
//int pi[10000];
string pi;
int s;

int levelSum(int n, int casenum, int order) {
//	int &sum = cache[n];
	int sum = 0;
	// base case
	if (n > s - 1) return sum = 0;
//	if (sum != -1) return sum;
	if (3 <= order && order <= 4) {	// 자릿수가 3 ~ 4 일때
		if (casenum == 1) {	// case 1
			if (pi[n] == pi[n + 1]) 
				return sum = min(levelSum(n + 1, 1, order + 1), levelSum(n + 1, 0, 0));
		}
		else if (casenum == 21) {	// case 2-1
			if (pi[n] + 1 == pi[n + 1]) 
				return sum = min(levelSum(n + 1, 21, order + 1), levelSum(n + 1, 0, 0));
		}
		else if (casenum == 22) {	// case 2-2
			if (pi[n] - 1 == pi[n + 1]) 	
				return sum = min(levelSum(n + 1, 22, order + 1), levelSum(n + 1, 0, 0));
		}
		else if (casenum == 3) {	// case 3
			if (pi[n + 1] == pi[n - 1])	
				return sum = min(levelSum(n + 1, 3, order + 1), levelSum(n + 1, 0, 0));
		}
		else if (casenum == 4) {	// case 4
			if (pi[n] - pi[n + 1] == pi[n - 1] - pi[n]) 
				return sum = min(levelSum(n + 1, 4, order + 1), levelSum(n + 1, 0, 0));
		}
		else if (casenum == 5)		// case 5
			return sum = min(levelSum(n + 1, 5, order + 1), levelSum(n + 1, 0, 0));
		return sum = levelSum(n + 1, 0, 0) ;
	}
	if (order == 5) {	// 자릿수 5 일 때
		return sum = levelSum(n + 1, 0, 0);
	}
	else {	// 자릿수 1 ~ 2 일 때
		if (n + 2 > s - 1) return sum = 1000000000; // 뒤에 남는 자릿수일 경우
		if (pi[n] == pi[n + 1] && pi[n + 1] == pi[n + 2])	// case 1
			sum = 1 + levelSum(n + 2, 1, 3);
		else if (pi[n] + 1 == pi[n + 1] && pi[n + 1] + 1 == pi[n + 2])	// case 2-1
			sum = 2 + levelSum(n + 2, 21, 3);
		else if (pi[n] - 1 == pi[n + 1] && pi[n + 1] - 1 == pi[n + 2])	// case 2-2
			sum = 2 + levelSum(n + 2, 22, 3);
		else if (pi[n] == pi[n + 2])	// case 3
			sum = 4 + levelSum(n + 2, 3, 3);
		else if (pi[n] - pi[n + 1] == pi[n + 1] - pi[n + 2])	// case 4
			sum = 5 + levelSum(n + 2, 4, 3);
		else	// case 5
			return sum = 10 + levelSum(n + 2, 5, 3);
		return sum = min(sum, 10 + levelSum(n + 2, 5, 3));
	}
}
int main() {
	int n, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//memset(cache, -1, sizeof(cache));
		cin >> pi;
		s = pi.size();
		cout << levelSum(0, 0, 0) << endl;
	}
	return 0;
}
