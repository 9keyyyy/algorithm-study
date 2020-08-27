#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here) {
	cout << "DFS visits" << here << endl;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}

void dfsAll() {
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < adj.size(); i++)
		if (!visited[i])
			dfs(i);
}

/*
	위상정렬 구현 
		-> dfs()가 종료할때마다 현재 정점의 번호를 기록
		-> dfs()가 늦게 종료한 정점일수록 정렬 결과의 앞에 옴
*/
