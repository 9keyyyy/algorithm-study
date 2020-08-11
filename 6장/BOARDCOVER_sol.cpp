#include <iostream>
#include <vector>
using namespace std;

// 새로 채워질 칸들의 상대좌표 (주어진 칸을 덮을 수 있는 네가지 방법)
const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};
// vector<int> : 자동으로 메모리가 할당되는 1차원 배열 template
// vector<vector<int>> : 2차원 배열
bool set(vector<vector<int>> &board, int y, int x, int type, int delta) {

	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover(vector<vector<int>> &board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}
		/*
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		*/
		set(board, y, x, type, -1);
	}
	return ret;
}
int main() {
	
	int m, cnt = 0, H, W;
	char in;
	cin >> m;
	while (1) {
		vector<vector<int>> board;
		if (m == cnt) break;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			vector<int> tmp;
			for (int j = 0; j < W; j++) {
				cin >> in;
				if (in == '.') tmp.push_back(0);
				else if (in == '#') tmp.push_back(1);
			}
			board.push_back(tmp);
		}
		/*
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		*/
		cout << cover(board) << endl;
		cnt++;
	}
	return 0;
}
