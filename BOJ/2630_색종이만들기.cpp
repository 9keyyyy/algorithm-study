// 분할 정복
// 4ms
#include <iostream>
using namespace std;

int N;
int board[128][128];
int color[2] = {0, 0};

// 네 조각의 색이 모두 같은지 확인
int isSame(int s, int e, int length) {
	if (board[s][e] == board[s + length][e] && board[s + length][e] == board[s][e + length] && board[s][e + length] == board[s + length][e + length])
		return 1;
	else
		return 0;
}
// 위아래/좌우 4개로 분할해 색이 같은지 확인
int countDivide(int s, int e, int length) {

	length /= 2;
	// basecase
	if (length < 1) return 1;

	int upL = countDivide(s, e, length);
	int upR = countDivide(s + length, e, length);
	int downL = countDivide(s, e + length, length);
	int downR = countDivide(s + length, e + length, length);
	// 각 부분들이 모두 하나의 색으로만 이루어져 있고, 그 색들이 모두 같을 때
	if (upL == 1 && upR == 1 && downL == 1 && downR == 1 && isSame(s, e, length)) return 1;
	// 그 외
	if (upL) color[board[s][e]] += 1;
	if (upR) color[board[s + length][e]] += 1;
	if (downL) color[board[s][e + length]] += 1;
	if (downR) color[board[s + length][e + length]] += 1;
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	if(countDivide(0, 0, N)) color[board[0][0]]++;
	cout << color[0] << endl << color[1];
}