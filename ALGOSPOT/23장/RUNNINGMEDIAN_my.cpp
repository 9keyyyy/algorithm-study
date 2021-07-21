#include <iostream>
#include <vector>
using namespace std;
/*-------------------------------------------------------------------------------------------------

	,,, 시간초과 ,,,

	< 생각한 알고리즘 >
	
	힙을 구현하는 함수와 힙에서 항상 최댓값을 pop하는 함수를 이용해 힙 정렬 구현 (내림차순)
	정렬된 배열에서 중간값 찾음 
	-> n 홀수일 때 n/2 인덱스, 짝수일 때 (n/2)와 (n/2-1) 인덱스 비교후 중간값 리턴,,,

--------------------------------------------------------------------------------------------------*/

vector<int> heap;

void push_heap(vector<int>& heap, int newValue) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}
int pop_heap(vector<int> &heap) {
	int M = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[next] < heap[left]) next = left;
		if (right < heap.size() && heap[next] < heap[right]) next = right;
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}
	return M;
}
struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};
int FindMedian(vector<int> heap, int n, RNG rng) {
	int sum = 0, idx = 0;
	for (int i = 0; i < n ; i++) push_heap(heap, rng.next());
	vector<int> Sort;
	for (int i = 0; i < n; i++) {
		Sort.push_back(pop_heap(heap));
	}
	int half = n / 2;
	int M1 = Sort[half], M2;
	if (n % 2 == 0) {
		M2 = Sort[half - 1];
		if (M2 < M1) return M2;
	}
	return M1;
}

int main() {
	int n, m, a, b;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m >> a >> b;
		int sum = 0;
		RNG rng(a, b);
		for (int j = 1; j < m + 1; j++) sum += FindMedian(heap, j, rng) % 20090711;
		cout << sum << endl;
	}
}
