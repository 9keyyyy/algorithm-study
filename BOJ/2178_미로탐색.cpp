// 20220508
// BFS
using namespace std;
#include <iostream>
#include <queue>

int N, M;
int map[101][101];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
queue<pair<int, int>> q;

void bfs() {
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] == 1) {
				map[ny][nx] = map[y][x] + 1;
				if (ny == N - 1 && nx == M - 1) cout << map[ny][nx];
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j]-'0';
		}
	}
	bfs();

	return 0;
}