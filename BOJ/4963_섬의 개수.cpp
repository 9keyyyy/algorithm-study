// 20220504
// dfs
using namespace std;
#include <iostream>
#include <string.h>
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int visited[51][51];
int map[51][51];
int cnt, w, h;

void dfs(int x, int y) {
	visited[x][y] = 1;
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (!visited[nx][ny] && map[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	while (1) {
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(visited));
		cnt = 0;
		
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}