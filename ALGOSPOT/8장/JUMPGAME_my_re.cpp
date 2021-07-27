// 동적 계획법
// 32ms
#include <iostream>
#include <string.h>
using namespace std;

int cache[100][100];
int board[100][100];
int bsize;

int jumpgame(int y, int x) {
	// basecase
	if (y == bsize - 1 && x == bsize - 1) return 1;

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	// y축 방향
	if (y + board[y][x] < bsize)
		ret = jumpgame(y + board[y][x], x);
	// x축 방향
	if (x + board[y][x] < bsize && ret != 1) {
		ret = jumpgame(y, x + board[y][x]);
		if (ret != 1) ret = 0;
	}
	return ret;
}
int main() {
	int C;
	
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> bsize;
		for (int j = 0; j < bsize; j++) {
			for (int k = 0; k < bsize; k++) {
				cin >> board[j][k];
			}
		}
		int ret = jumpgame(0, 0);
		if (ret == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}