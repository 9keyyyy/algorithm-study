// 20220705
// dfs, map 
#include <iostream>
#include <map>
using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

map<string, int> m;
char s[11][11];
string cur;
int N, M, K;

void dfs(int y, int x, int d, string str) {
	if (d == 5) return;
	m[str]++;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0) ny = N - 1;
		if (nx < 0) nx = M - 1;
		if (ny >= N) ny = 0;
		if (nx >= M) nx = 0;

		dfs(ny, nx, d + 1, str + s[ny][nx]);
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> s[i][j];
		}
	}

	string str;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			str = "";
			dfs(i, j, 0, str + s[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> str;
		cout << m[str] << endl;
	}
	return 0;
}