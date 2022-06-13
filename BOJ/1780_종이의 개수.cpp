// 20220610
// 분할정복
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> arr;
int result[3] = { 0 };
void sol(int r, int c, int n) {
	int s = arr[r][c], flag = 0;

	for (int i = r; i < r+n; i++) {
		for (int j = c; j < c+n; j++) {
			if (s != arr[i][j]) flag = 1;
		}
	}
	if (flag == 0) result[s]++;
	else {
		int dist = n / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sol(r + dist * i, c + dist * j, dist);
			}
		}
	}

}	

int main() {
	int e;
	cin >> N;
	arr = vector<vector<int>>(N + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> e;
			e++;
			arr[i].push_back(e);
		}
	}
	sol(0, 0, N);
	cout << result[0] << endl;
	cout << result[1] << endl;
	cout << result[2] << endl;


}
