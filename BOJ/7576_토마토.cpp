// 20220506
// BFS
using namespace std;
#include <iostream>
#include <queue>


int M, N;
int map[1001][1001];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}


int main() {
	int res = 0;
	cin >> M >> N;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	
	bfs();


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			if (res < map[i][j]) res = map[i][j];
		}
	}
	cout << res - 1;

	return 0;
}