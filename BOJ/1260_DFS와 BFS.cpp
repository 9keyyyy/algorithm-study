// 2022-02-09 BOJ 1260 DFS와 BFS
// DFS BFS 인접리스트 사용
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 그래프의 인접 리스트 표현
vector<vector<int>> adj;
// 각 정점을 방분했는지 여부
vector<bool> visited;

// 깊이 우선 탐색 구현
void dfs(int here) {
	cout << here << " ";
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		// 아직 방문한 적 없으면 방문
		if (!visited[there])
			dfs(there);
	}
}
// 모든 정점을 방문하도록
void dfsAll() {
	// visited 모두 false로 초기화
	visited = vector<bool>(adj.size(), false);
	// 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문
	for (int i = 0; i > adj.size(); i++)
		if (!visited[i]) dfs(i);
}

// 너비 우선 탐색 구현
// start에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환
vector<int> bfs(int start) {
	// 각 정점의 방문 여부
	vector<bool> discovered(adj.size(), false);
	// 방문할 정점 목록을 유지하는 큐
	queue<int> q;
	// 정점의 방문순서
	vector<int> order;

	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		//here 방문
		order.push_back(here);
		//모든 인접 정점 검사
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			// 처음 보는 정점이면 방문 목록에 집어넣음
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}

int main() {
	int N, M, V, s, e;
	cin >> N >> M >> V;
	adj = vector<vector<int>>(N + 1);
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for (int i = 0; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	
	dfs(V);
	cout << "\n";
	vector<int> order = bfs(V);
	for (int i = 0; i < order.size(); i++)
		cout << order[i] << " ";
}