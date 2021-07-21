#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
/*----------------------------------------------------------------------------------------------------------
	
	RTE (SIGSEGV: segmentation fault, probably incorrect memory access or stack overflow)

	< 생각한 알고리즘 >

	입력받은 단어들의 알파벳 순서를 찾고, 전체 알파벳 순서를 수정해 반환
	dicS : 입력받은 단어들의 알파벳 순서
	origin: 원래 알파벳 순서

	두 단어 비교시,
	1. 알파벳이 중복될 경우
		- 알파벳이 중복되지 않을때까지 위치를 하나씩 옮겨 찾고, dicS에 해당 알파벳이 있는지 찾음
		- 한 단어의 알파벳만 dicS에 존재할 경우 : 나머지 하나의 단어 순서 생각해서 dicS에 추가
		- 둘다 dicS에 존재할 경우 : dicS와 현재 두 단어의 알파벳 순서 비교 후 다를 경우 invalid 반환
		- 둘다 dicS에 존재하지 않을 경우 : 차례로 dicS에 알파벳 push_back()
	2. 그렇지 않을 경우 
		- dicS에 이미 존재하는 알파벳일 경우 invalid 반환
		- 그렇지 않을 경우 push_back()
	3. origin과 disC에서 중복되는 단어 제거 후 origin + disC

-----------------------------------------------------------------------------------------------------------*/

string dicS;
string str[201];

string Sortdic(int n) {
	string origin = "abcdefghijklmnopqrstuvwxyz";
	string invalid = "INVALID HYPOTHESIS";
	int idx = 0;

	for (int i = 0; i < n; i++) {
		idx = 0;
		if (i != 0 && str[i - 1][idx] == str[i][idx]) {
			while (str[i - 1][idx] == str[i][idx]) idx++;
			if (str[i - 1][idx] == '\0' || str[i][idx] == '\0') continue;
			int r1 = dicS.find(str[i - 1][idx]), r2 = dicS.find(str[i][idx]);
			if (r1 == -1 && r2 != -1) {
				string sub1 = dicS.substr(0, r2);
				string sub2 = dicS.substr(r2);
				dicS = sub1 + str[i - 1].substr(idx, 1) + sub2;
			}
			else if (r1 != -1 && r2 == -1) {
				string sub1 = dicS.substr(0, r1 + 1);
				string sub2 = dicS.substr(r1 + 1);
				dicS = sub1 + str[i].substr(idx, 1) + sub2;
			}
			else if (r1 != -1 && r2 != -1) {
				if (r1 > r2) return invalid; 
			}
			else {
				dicS.push_back(str[i - 1][idx]);
				dicS.push_back(str[i][idx]);
			}
		}
		else {
			int r = dicS.find(str[i][idx]);
			if (r == -1) dicS.push_back(str[i][idx]);
			else return invalid;
		}
	}
	for (int i = 0; i < dicS.size(); i++) {
		int r = origin.find(dicS[i]);
		if (r != -1) origin.erase(r, 1);
	}
	origin = dicS + origin;
	return origin;
}
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> str[j];
		}
		cout << Sortdic(m) << endl;
		dicS.clear();
	}
	return 0;
}
