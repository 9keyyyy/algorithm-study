// 완전 탐색
// 4ms
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int C, N, M;
int isPair[10];			// 학생이 선택되었는지 여부를 나타냄 (0 : 선택X, 1 : 선택O)
int isFriend[45][2];	// 입력받은 친구 pair들의 배열
int sum = 0;

// n : 총 친구 pair 수, picked : 지금까지 선택된 친구pair(isFriend)의 인덱스, toPick : 더 골라야 할 친구pair의 수
void pickPair(int n, vector<int>& picked, int toPick) {	
	// basecase
	if (toPick == 0) sum++;

	// 가장 작은 인덱스부터 선택
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	// 친구 pair 선택
	for (int next = smallest; next < n; next++) {
		// 한 쌍의 친구pair가 모두 선택되지 않았을 경우에만 선택함
		if (isPair[isFriend[next][0]] == 0 && isPair[isFriend[next][1]] == 0) {
			isPair[isFriend[next][0]] = 1; isPair[isFriend[next][1]] = 1;
			picked.push_back(next);
			pickPair(n, picked, toPick - 1);
			isPair[isFriend[picked.back()][0]] = 0; isPair[isFriend[picked.back()][1]] = 0;
			picked.pop_back();
		}
	}
}

int main() {
	vector<int> picked;

	cin >> C; 
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		memset(isFriend, 0, sizeof(isFriend));
		memset(isPair, 0, sizeof(isPair));
		sum = 0;
		for (int j = 0; j < M; j++)
			cin >> isFriend[j][0] >> isFriend[j][1];
		pickPair(M, picked, N/2);
		cout << sum << endl;
	}
}