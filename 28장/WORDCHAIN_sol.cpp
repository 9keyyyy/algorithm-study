#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // 인접 행렬
vector<string> graph[26][26]; // i로시작해 j로 긑나는 단어 목록
vector<int> indegree, outdegree;  // i로 시작하는 단어 수, 끝나는 단어 수

// 입력 그래프로 변환
void makeGraph(const vector<string> &words) {
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	for (int i = 0; i < words.size(); ++i) {
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}






// 방향 그래프에서 오일러 서킷/트레일 찾기

// 유향 그래프의 인접행렬 adj가 주어질 때 오일러 서킷 혹은 트레일 계산
void getEulerCircuit(int here, vector<int> &circuit) {
	for (int there = 0; there < adj[here].size(); ++there)
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}
// 현재 그래프의 오일러 트레일이나 서킷 반환
vector<int> getEulerTrailOrCircit() {
	vector<int> circuit;
	// 먼저 트레일 찾음
	for (int i = 0; i < 26; i++)
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	// 트레일이 아닐 경우 서킷
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	// 모두 실패한 경우 빈 배열 반환
	return circuit;
}






// 문제를 오일러 트레일로 바꿔 해결하는 알고리즘

// 현재 그래프의 오일러 서킷/트레일 존재여부 확인
bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; ++i) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words) {
	makeGraph(words);
	if (!checkEuler()) return "IMPOSSIBLE";
	vector<int> circuit = getEulerTrailOrCircit();
	if(circuit.size()!=words.size()) return  "IMPOSSIBLE";

	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 0; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}