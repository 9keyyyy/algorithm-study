// 여행하는 외판원 문제
// 완전 탐색
#include <iostream>
#include <vector>
#define MAX 100
#define INF 987654321
using namespace std;

int n; // 도시의 수
double dist[MAX][MAX]; // 두 도시간의 거리 저장하는 배열
// path: 지금까지 만든 경로
// visited: 각 도시의 방문 여부
// currendLength: 지금까지 만든 경로 길이
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환하는 함수
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
	// basecase: 모든 도시를 다 방문했을 때는 시작도시로 돌아가고 종료
	if (path.size() == n)
		return currentLength + dist[path[0]][path[path.back()]];
	double ret = INF;	// 매우 큰 값으로 초기화
	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// 나머지 경로를 재귀호출을 통해 완성하고 가장 짧은 경로의 길이 얻음
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

