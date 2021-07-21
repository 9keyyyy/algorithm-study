#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >

	memorization 사용해보려 했지만 어떻게 사용해야할 지 감이 안와서,
	완전 탐색 방법으로 모든 경우 비교해봄

	와일드 카드 패턴에서 '*'가 나왔을 때 발생 가능한 여러 경우의 수가 있기 때문에,
	 -> 반복문과 재귀 호출을 통해 참 값이 나올 때까지 모든 경우 비교
	 -> 문자열이 끝났을 경우 반복문 종료

	4ms

-------------------------------------------------------------------------------------------*/

int Check(char *card, char *name) {
	int ret = 0;
	// base case : 와일드카드 패턴과 파일명 문자열이 모두 끝났을 때
	if (*card == '\0'&&*name == '\0') return 1;
	
	// 1. (와일드 카드 패턴 = 파일명) 혹은 (와일드 카드 패턴 = '?') 일 때
	if (*card == *name || *card == '?') return ret = Check(++card, ++name);
	// 2. (와일드 카드 패턴 = '*') 일 때
	if (*card == '*') {
		while (*card == '*') ++card;
		if (*card == '\0') return 1;
		// 결과가 참이 될때까지 모든 경우를 비교해보고, 파일명이 문자열 끝에 도달했을 때는 반복문 탈출 
		while (ret != 1) {
			while (*name != *card) {
				if (*name == '\0') return -1;
				if (*card == '?') break;
				++name;
			}
			// 참 값이 안나왔을 때를 대비해, 패턴의 현재 인덱스 및 파일명 문자열 인덱스 (+1) 한 주소 기억
			char *tmpcard = card, *tmpname = name + 1;
			// 패턴의 '*' 다음문자와 현재 파일명 문자가 같다면, 재귀로 각각 다음 문자 넘겨줌
			ret = Check(++card, ++name);
			if (*name == '\0') break;
			card = tmpcard; name = tmpname;
		}
		return ret;
	}

	if (*card == '\0' || *name == '\0') return -1;
}
int main() {
	int n, m, cnt;
	char in[101], name[101], res[101][101];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		cin >> in;
		cin >> m;
		char tmp[101];
		strcpy(tmp, in);
		for (int j = 0; j < m; j++) {
			strcpy(in, tmp);
			cin >> name;
			if (Check(in, name) == 1) { 
				strcpy(res[cnt++], name); 
			}

		}
		// 정렬
		for (int j = 0; j < cnt; j++) {
			for (int k = j+1; k < cnt; k++) {
				if (strcmp(res[j], res[k]) > 0) {
					strcpy(tmp, res[j]);
					strcpy(res[j], res[k]);
					strcpy(res[k], tmp);
				}
			}
		}
		for (int j = 0; j < cnt; j++)
			cout << res[j] << endl;
	}
	return 0;
}