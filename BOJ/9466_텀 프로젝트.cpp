//20220411 BOJ 9466 텀 프로젝트
// dfs
using namespace std;
#include <iostream>
#include <vector>


vector<int> visited;
vector<int> adj;
int T, N, e;

// DFS ver---------------------------------
int cnt;
vector<int> done;
void dfs1(int here) {
	visited[here] = 1;
	int next = adj[here];
	if (!visited[next]) dfs1(next);
	else if (!done[next]) {
		for (int i = next; i != here; i = adj[i]) cnt++;
		cnt++;
	}
	done[here] = true;
}
void dfsAll1() {
	for (int i = 1; i <= N; i++)
		if (!visited[i]) dfs1(i);
}
//-------------------------------------------
// 시간초과 DFS ver--------------------------
vector<int> res;
void checkres(int idx) {
	if (visited[idx] == 3) return;
	res[idx] = 1;
	visited[idx]++;
	checkres(adj[idx]);
}
void dfs2(int here) {
	visited[here]++;
	if (visited[here] == 2) { 
		checkres(here);
		visited.assign(N + 1, 0);
		return; 
	}
	dfs2(adj[here]);
}
int dfsAll2() {
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (res[i] == 0) dfs2(i);
	}
	for (int i = 1; i <= N; i++) {
		if (res[i] == 0) {
			result++;
		}
	}
	return result;
}
//-------------------------------------------
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cnt = 0;
		adj = vector<int>(N + 1);
		visited = vector<int>(N + 1, 0);
		done = vector<int>(N + 1, 0);
		for (int j = 1; j <= N; j++) {
			cin >> e;
			adj[j] = e;
		}
		dfsAll1();
		cout << N-cnt << "\n";
	}
}