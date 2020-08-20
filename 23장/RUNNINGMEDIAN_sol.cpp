#include <iostream>
#include <queue>
using namespace std;

/*
	우선순위 큐 사용 (heap의 구현)
	최대부터 빠지는 걸 Max Heap, 최소부터 빠지는 걸 Min Heap이라고 함
	Maxheap, Minheap 선언해 Maxheap에서 항상 중간값을 pop할 수 있도록 설정
	Minheap에는 중간값 이후부터의 값 저장, Maxheap에는 중간값 아래로 값 저장
*/

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};
int runningMedian(int n, RNG rng) {
	// 우선순위 큐 : < datatype, container type, 정렬기준 >
	priority_queue<int, vector<int>, less<int>> maxHeap; // 큰것부터 pop
	priority_queue<int, vector<int>, greater<int>> minHeap; // 작은것부터 pop
	int ret = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}
/*
int runningMedian(int n, RNG rng) {
	Node *root = NULL;
	int ret = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		root = insert(root, new Node(rng.next()));
		int median = kth(root, (cnt + 1) / 2)->key;
		ret = (ret + median) % 20090711;
		return ret;
	}
}
*/
