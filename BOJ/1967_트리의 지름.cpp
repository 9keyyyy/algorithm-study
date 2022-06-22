// 20220623
// dfs
// point. 한 정점에서 가장 멀리 떨어진 정점은 지름의 끝점에 해당
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int>> adj[10001];
int visited[10001] = {0};

int end_point = 0;		// 지름 끝점
int res = 0;			// 지름

void dfs(int cur, int d) {
	if (visited[cur]) return;
	visited[cur] = 1;

	if (res < d) {
		res = d;
		end_point = cur;
	}

	for (int i = 0; i < adj[cur].size(); i++) {
		dfs(adj[cur][i].first, d + adj[cur][i].second);
	}
}

int main() {
	int V, p, v, d;
	cin >> V;

	for (int i = 0; i < V - 1; i++) {
		cin >> p >> v >> d;
		adj[p].push_back(make_pair(v, d));
		adj[v].push_back(make_pair(p, d));
	}

	// 지름의 끝 점(end_point) 구하기
	dfs(1, 0);
	
	// 지름 구하기(end_point와 가장 멀리 떨어진 점)
	res = 0;
	memset(visited, 0, sizeof(visited));
	dfs(end_point, 0);
	
	cout << res;

	return 0;
}