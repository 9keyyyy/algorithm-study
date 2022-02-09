#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;

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