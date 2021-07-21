#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(vector<int> &clocks) {
	int flag = 0;
	for (int i = 0; i < 16; i++) {
		if (clocks[i] != 12) flag = 1;
	}
	if (flag == 0) return true;
	else return false;
}

void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	// 스위치 3번 누르는 것까지 시도
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}

int main() {
	vector<int> clocks(16);
	int n, result;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 16; j++) {
			cin >> clocks[j];
		}
		result = solve(clocks, 0);
		if (result == INF) cout << "-1" << endl;
		else cout << result << endl;
	}

	return 0;
}