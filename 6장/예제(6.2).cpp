#include <iostream>
#include <vector>
using namespace std;
/********************************************/
// 1부터 n까지 합을 반환하는 함수

// 비재귀버전
int sum(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) ret += i;
	return ret;
}
// 재귀버전
int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n - 1);
}
/********************************************/
// 중첩 반복문 대체하기

// 비재귀 - 0부터 차례대로 번호 매겨진 n개의 원소 중 네개를 고르는 모든 경우 출력
void selectFour(int n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				for (int l = k + 1; l < n; l++)
					cout << i << " " << j << " " << k << " " << l << endl;
}
// 재귀 - n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
// n : 전체 원수의 수, picked : 지금까지 고른 원소들의 번호, toPick : 더 골라야하는 원소의 수
void pick(int n, vector<int>& picked, int toPick) {
	// basecase
	if (toPick == 0) {
		for (int i = 0; i < picked.size(); i++) cout << picked[i] << " ";
	}

	// 고를수 있는 가장 작은 번호 계산
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	// 원소 고름
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}
/********************************************/
int main() {
	vector<int> picked;
	pick(4, picked, 2);
}