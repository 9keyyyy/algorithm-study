// 20220525
// BFS
using namespace std;
#include <iostream>
#include <vector>
#include <queue>

int N;
vector<vector<int>> graph;
vector<int> arr;
queue<int> q;

void sol() {
	q.push(1);
	while (!q.empty()) {
		int e = q.front();
		q.pop();

		for (int i = 0; i < graph[e].size(); i++) {
			int v = graph[e][i];
			if (arr[v] != 0) continue;
			q.push(v);
			arr[v] = e;
		}
	}
}

int main() {
	int s, e;
	cin >> N;
	
	graph = vector<vector<int>>(N + 1);
	arr = vector<int>(N + 1, 0);
	
	for (int i = 1; i < N; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	sol();
	for (int i = 2; i < N + 1; i++) printf("%d\n", arr[i]);

	return 0;
}