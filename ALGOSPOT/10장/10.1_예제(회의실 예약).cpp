// 탐욕법
// 20220207
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int beginTime[100], endTime[100];
int schedule() {
	// 일찍 끝나는 순으로 정렬
	vector<pair<int, int>> order;
	for (int i = 0; i < n; i++)
		order.push_back(make_pair(beginTime[i], endTime[i]));
	sort(order.begin(), order.end());
	// earlist : 다음 회의가 시작할 수 있는 가장 빠른 시간
	// selected : 지금까지 선택한 회의 수
	int earliest = 0, selected = 0;
	for (int i = 0; i < order.size(); i++) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;
		if (earliest <= meetingBegin) {
			earliest = meetingEnd;
			++selected;
		}
	}
	return selected;
}