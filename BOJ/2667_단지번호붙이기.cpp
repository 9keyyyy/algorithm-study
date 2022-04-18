// 20220418 BOJ 2667 단지번호붙이기
// dfs
using namespace std;
#include <iostream>
#include <deque>
#include <algorithm>
int cnt;
int adj[25][25];
bool visited[25][25];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int N) {
	cnt++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (adj[nx][ny] == 1 && !visited[nx][ny]) dfs(nx, ny, N);
	}
}

int main() {
	int N;
	string s;
	deque<int> result;
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			adj[i][j] = s[j]-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adj[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				dfs(i, j, N);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int n : result) cout << n << "\n";

	return 0;
}

