//20220410 BOJ 2331 반복수열
// ver1. stl
// ver2. dfs 
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int A, P;


// ver1 - stl
vector<int> arr;
int returnValue(int num) {
	int res = 0;
	while (num) {
		res += pow(num % 10, P);
		num /= 10;
	}
	A = res;
	return res;
}
int findLeft() {
	int res;
	vector<int>::iterator idx;
	arr.push_back(A);
	while (1) {
		res = returnValue(A);
		idx = find(arr.begin(), arr.end(), res);
		if (idx == arr.end()) arr.push_back(res);
		else break;
	}
	return idx-arr.begin();
}

// ver2 - dfs
vector<int> visited = vector<int>(300001, 0);
int dfs(int here) {
	visited[here]++;
	// 구간이 한번 반복되었을 경우 return (반복구간에서 제외된 수들의 개수를 구하기 위함)
	if (visited[here] == 3) return;
	int res = 0;
	while (here) {
		res += pow(here % 10, P);
		here /= 10;
	}
	dfs(res);
}
int dfsSearch() {
	int res = 0;
	for (int i = 0; i < 300001; i++)
		if (visited[i] == 1) res++;
	return res;
}


int main() {
	cin >> A >> P;
	cout << findLeft();
}