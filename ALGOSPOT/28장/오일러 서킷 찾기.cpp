// 깊이 우선 탐색을 이용한 오일러 서킷 찾기

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
void getEulerCircuit(int here, vector<int> &circuit) {
	for(int there = 0; there<adj[here].size();++there)
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}