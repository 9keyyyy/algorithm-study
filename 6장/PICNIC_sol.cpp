#include <iostream>
using namespace std;

int n;
bool areFriend[10][10] = { false };

int countParings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriend[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {

	int m, cnt, s = 0;
	int f1, f2;
	bool taken[10] = { false };

	cin >> m;
	while (1) {
		cin >> n >> cnt;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				areFriend[i][j] = false;
			}
			taken[i] = false;
		}
		for (int i = 0; i < cnt; i++) {
			cin >> f1 >> f2;
			areFriend[f1][f2] = true;
			areFriend[f2][f1] = true;
		}
		cout << countParings(taken) << endl;
		s++;
		if (s == m) break;
	}
	


	return 0;
}
