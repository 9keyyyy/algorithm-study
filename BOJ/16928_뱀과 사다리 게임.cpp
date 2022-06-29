// 20220629
// bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr;	
vector<int> dist;	

int sol() {
	dist[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int res = cur + i;
			if (res > 100) continue;
			res = arr[res];
			if (dist[res] == -1) {
				dist[res] = dist[cur] + 1;
				q.push(res);
			}
		}
	}

	return dist[100];
}

int main() {
	int N, M, a, b;
	arr = vector<int>(101, 0);
	dist = vector<int>(101, -1);
		
	for (int i = 1; i < 101; i++) {
		arr[i] = i;
	}

	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> a >> b;
		arr[a] = b;
	}	
	
	cout << sol();
	
	return 0;
}
