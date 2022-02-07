// 탐욕법
// 20220207
// 4ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> korea, rusia;
int M, N, score;
// my solution
// 두 배열을 오름차순 정렬하고, 앞에서부터 비교해가면서 win 개수 셈
int calculateMaxWin() {
	sort(korea.begin(), korea.end());
	sort(rusia.begin(), rusia.end());
	int win = 0, idx = 0;
	for (int i = 0; i < korea.size(); i++) {
		if (korea[i] < rusia[idx]) continue;
		idx++;
		win++;
		if (idx == rusia.size()) break;
	}
	return win;
}

// book solution
// 1. 상대방 선수를 이길 수 있는 선수가 있을 경우 
//    그 중 rating이 가장 낮은 선수와 상대방 선수 경기시킴
// 2. 상대방 선수가 우리팀의 모든 선수보다 rating이 높다면
//    우리 선수중 가장 rating 낮은 선수와 경기 시킴
int order(const vector<int>& rusia, const vector<int>& korea) {
	int n = rusia.size(), wins = 0;
	// 아직 남아있는 선수들의 레이팅
	// multiset<> : 이진트리 형식으로 오름차순으로 정렬해 저장
	multiset<int> ratings(korea.begin(), korea.end());
	for (int rus = 0; rus < N; rus++) {
		// rbegin() : 배열의 마지막 원소 (end()의 경우 마지막 원소 뒤 인덱스 가리킴)
		if (*ratings.rbegin() < rusia[rus]) 
			ratings.erase(ratings.begin());
		else {
			ratings.erase(ratings.lower_bound(rusia[rus]));
			wins++;
		}
	}
	return wins;
}
int main() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> N;
		korea.clear();
		rusia.clear();
		for (int j = 0; j < N; j++) {
			cin >> score;
			rusia.push_back(score);
		}
		for (int j = 0; j < N; j++) {
			cin >> score;
			korea.push_back(score);
		}
		cout << calculateMaxWin() << endl;
	}

	return 0;
}