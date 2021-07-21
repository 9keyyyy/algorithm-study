#include <iostream>
using namespace std;

int n, board[100][100];
int cache[100][100];

bool jump2(int y, int x) {
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	
	int &ret = cache[y][x]; 
	if (ret != -1) return ret;
	int jumpSize = board[y][x];

	return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}
int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				cin >> board[j][k];
		if (jump2(0, 0) == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}