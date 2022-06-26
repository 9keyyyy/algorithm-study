// 20220626
// dfs
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, p, c, w;
vector<pair<int, int>> adj[100001];
int visited[100001] = { 0 };

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
	cin >> V;

	for (int i = 0; i < V; i++) {
		cin >> p;
		while (1) {
			cin >> c;
			if (c == -1) break;
			cin >> w;
			adj[p].push_back(make_pair(c, w));
			//adj[c].push_back(make_pair(p, w));
		}
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