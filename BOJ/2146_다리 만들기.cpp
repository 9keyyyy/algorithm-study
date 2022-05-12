// 20220512
// BFS-leveling skill
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

int map[101][101];
int visited[101][101] = { 0 };
int N;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
queue<pair<int, int>> q;

void checkIsland(int b, int a, int label) {
	queue<pair<int, int>> tmpQ;
	tmpQ.push(make_pair(b, a));
	visited[b][a] = 1;
	map[b][a] = label;

	while (!tmpQ.empty()) {
		int y = tmpQ.front().first;
		int x = tmpQ.front().second;
		tmpQ.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (map[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				map[ny][nx] = label;
				tmpQ.push(make_pair(ny, nx));
			}
		}
	}
}

int bfs(int n) {
	queue<pair<int, int>> tmpQ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == n) {
				visited[i][j] = 1;
				tmpQ.push(make_pair(i, j));
			}
		}
	}

	int res = 0;
	// bfs-leveling skill
	while (!tmpQ.empty()) {
		int s = tmpQ.size();
		for (int i = 0; i < s; i++) {
			int y = tmpQ.front().first;
			int x = tmpQ.front().second;
			tmpQ.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (map[ny][nx] != 0 && map[ny][nx] != n) return res;
				if (map[ny][nx] == 0 && !visited[ny][nx]) {
					visited[ny][nx] = 1;
					tmpQ.push(make_pair(ny, nx));
				}
			}
		}
		res++;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push(make_pair(i, j));
		}
	}

	int label = 2;
	int s = q.size();

	for (int i = 0; i < s; i++) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (!visited[y][x]) {
			checkIsland(y, x, label);
			label++;
		}
	}

	int res = 201;
	for (int i = 2; i < label; i++) {
		memset(visited, 0, sizeof(visited));
		res = min(res, bfs(i));
		
	}
	cout << res;

	return 0;
}