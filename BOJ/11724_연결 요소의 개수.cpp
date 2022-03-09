// 20220309 BOJ 11724 연결 요소의 개수
// 그래프
/*
*	dfs() 함수는 시작한 정점에서 갈 수 있는 모든 정점 방문
*   즉, 한 점에서 dfs() 호출하면 같은 컴포넌트에 속한 점 모두 방문
*   -> dfsAll() 에서 dfs()를 호출하는 횟수를 세면 됨!
*/
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

vector<vector<int>> adj;
vector<bool> visited;
int componentNum = 0;

void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}
void dfsAll() {
	visited = vector<bool>(adj.size(), false);
	for (int i = 1; i < adj.size(); i++) {
		if (!visited[i]) { 
			componentNum++;
			dfs(i); 
		}
	}
}
int main() {
	int N, M, s, e;
	cin >> N >> M;

	adj = vector<vector<int>>(N + 1);
	
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	dfsAll();
	cout << componentNum;
}