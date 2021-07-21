// 완전탐색
// 0 ms
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int card[100];

// M보다 크지 않으면서 M에 더 가까운 수 반환하는 함수
int CompareNum(int a, int b) {
	if (a <= M && a > b)
		return a;
	else return b;
}

// 문제에서 구하려는 수를 찾는 함수
// max : 구하려는 수, Picked : 지금까지 고른 카드들의 인덱스, toPick : 더 골라야하는 원소의 수
int findMax(vector<int> &Picked, int toPick, int max) {
	// basecase
	if (toPick == 0)
		return CompareNum(card[Picked[0]] + card[Picked[1]] + card[Picked[2]], max);

	// 고를 수 있는 가장 작은 인덱스 계산
	int first = Picked.empty() ? 0 : Picked.back() + 1;

	// 카드 고르기
	for (int next = first; next < N; next++) {
		Picked.push_back(next);
		max = findMax(Picked, toPick - 1, max);
		Picked.pop_back();
	}
	return max;
}
int main() {
	vector<int> Picked;
	int max = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> card[i];
	cout << findMax(Picked, 3, max);

}