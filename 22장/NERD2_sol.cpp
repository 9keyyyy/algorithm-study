#include <iostream>
#include <map>
using namespace std;

// map : 균형 이진트리 구조
map<int, int> coords;

bool isDominated(int x, int y) {
	// x보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점 찾기
	map<int, int>::iterator it = coords.lower_bound(x); // lower_bound() : 원소 x가 시작하는 구간의 반복자
	// 존재하지 않을 경우 지배당하지 않음
	if (it == coords.end()) return false;
	return y < it->second; // y좌표가 iterator의 y좌표 값보다 작은 경우 지배당함
}

// 새로운 점 (x, y)에 지배당하는 점들을 삭제
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x); // 원소 x가 시작하는 구간의 반복자
	if (it == coords.begin()) return; // iterator가 왼쪽에는 점이 없을 때
	--it;
	while (true) { 
		if (it->second > y) break;	// it가 표시하는 점이 지배되지 않는다면 반복문 탈출
		if (it == coords.begin()) { // 이전 점이 없을 경우 현재 it 지우고 종료
			coords.erase(it);
			break;
		}
		else { // 이전 점으로 iterator 하나 옮겨놓고 it 지움
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}

// 새 점 x, y가 추가되었을 때 coords 갱신하고, 지배당하지 않은 점들의 개수 반환
int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
