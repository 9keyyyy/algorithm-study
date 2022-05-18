// 20220518
// Greedy
using namespace std;
#include <iostream>
#include <algorithm>

int N, M, K;
int arr[1001];

int mySol() {
	int num = M / (K + 1);
	
	sort(arr, arr + N);
	for(int i = 0; i < N; i++) printf("%d ", arr[i]);
	return arr[N-2] * num + arr[N-1] * (M - num);

}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << mySol();

	return 0;
}