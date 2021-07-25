// 완전 탐색
// 0ms
#include <iostream>
#include <string.h>
using namespace std;

int board[20][20];
int H, W;
int block[12][2][2] = {
	{{-1, -1}, {0, -1}},
	{{0, -1}, {1, -1}},
	{{1, -1}, {1, 0}},
	{{1, 0}, {1, 1}},
	{{1, 1}, {0, 1}},
	{{0, 1}, {-1, 1}},
	{{-1, 1}, {-1, 0}},
	{{-1, 0}, {-1, -1}},
	{{0, -1}, {1, 0}},
	{{1, 0}, {0, 1}},
	{{-1, 0}, {0, 1}},
	{{-1, 0}, {0, -1}}
};
int sum = 0;

// 게임판을 벗어나는지 범위 확인하는 함수
int isRange(int x, int y){
	if (x < 0 || x >= W || y < 0 || y >= H) return 0;
	else return 1;
}
void fillBoard(int b[][20], int y, int x) {
	// 비어있는 다음 칸 찾음
	while (b[y][x] == 1) {
		if (x == W - 1) {
			if (y == H - 1) break;
			y++;
			x = -1;
		}
		x++;
	}
	// basecase
	if (y == H - 1 && x == W - 1) {
		sum++;
		return;
	}
	// 블럭으로 가능한 모든 경우의 수 시도
	for (int i = 0; i < 12; i++) {
		int y1 = y + block[i][0][1];
		int y2 = y + block[i][1][1];
		int x1 = x + block[i][0][0];
		int x2 = x + block[i][1][0];

		if (isRange(x1, y1) == 0 || isRange(x2, y2) == 0) continue;
		
		// 칸이 모두 비어있는 경우
		if (b[y][x] == 0 && b[y1][x1] == 0 && b[y2][x2] == 0) {
			b[y][x] = b[y1][x1] = b[y2][x2] = 1;
			fillBoard(b, y, x);
			b[y][x] = b[y1][x1] = b[y2][x2] = 0;
		}		
	}
}

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		memset(board, 0, sizeof(board));
		char tmp;
		sum = 0;
		cin >> H >> W;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> tmp;
				if (tmp == '#') board[j][k] = 1;
			}
		}
		fillBoard(board, 0, 0);
		cout << sum << endl;
	}
}