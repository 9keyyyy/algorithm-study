// 20220526
// BFS
#include <iostream>
#include <queue>
using namespace std;

struct shark {
	int y;
	int x;
	int size;
	int eat;
};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = {0, 0, -1, 1};

int map[21][21];
int dist[21][21];
struct shark s;
int N,  cnt = 0;

bool sol() {
	queue<pair<int, int>> q;
	q.push(make_pair(s.y, s.x));

	// distance 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = -1;
		}
	}
	dist[s.y][s.x] = 0;
	
	// bfs로 최단거리 찾기
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (dist[ny][nx] == -1 && map[ny][nx] <= s.size) {
				dist[ny][nx] = dist[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}

	// 최단거리 물고기 찾기
	int my = 21, mx = 21, m_dist = 987;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0 && map[i][j] != 9 && map[i][j] < s.size && dist[i][j] != -1 && dist[i][j] < m_dist) {
				m_dist = dist[i][j];
				my = i;
				mx = j;
			}
		}
	}

	// 더이상 map에 물고기가 없을 때
	if (m_dist == 987) {
		return false;
	}
	// 물고기가 있을 때
	else {
		map[s.y][s.x] = 0;
		s.y = my;
		s.x = mx;
		s.eat++;
		if (s.eat == s.size) {
			s.eat = 0;
			s.size++;
		}
		map[my][mx] = 9;
		cnt += dist[my][mx];
		return true;
	}
}

int main(){
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s.size = 2;
				s.eat = 0;
				s.y = i;
				s.x = j;
			}
		}
	}

	while (1) {
		if (sol()) continue;
		else break;
	}

	cout << cnt;
	
	return 0;
}