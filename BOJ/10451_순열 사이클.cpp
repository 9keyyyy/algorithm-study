//20220409 BOJ 10451 순열 사이클
// DFS
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

vector<vector<int>> adj;
vector<bool> visited;

int T, N, e, cycle;

void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (visited[there] == false) {
			dfs(there);
		}
	}
}
void dfsAll() {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			dfs(i);
			cycle++;
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cycle = 0;
		cin >> N;
		
		adj = vector<vector<int>>(N + 1);
		visited = vector<bool>(N + 1, false);

		for (int j = 1; j <= N; j++) {
			cin >> e;
			adj[j].push_back(e);
		}
		dfsAll();

		cout << cycle << "\n";
	}
}