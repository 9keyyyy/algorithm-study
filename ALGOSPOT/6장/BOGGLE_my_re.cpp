// 4ms
// 메모리제이션 적용 (동적계획법)
#include <iostream>
#include <string.h>

using namespace std;

char map[5][5];			// board
int memory[10][5][5];	// memorization
string word;
int N, M;

// 현재 위치에서 상하좌우/대각선에 다음 문자가 있는지 확인하는 함수
// 반환값 - 0 : 다음문자X, 1 : 다음문자O, 2 : 단어가 게임판에 존재함
int IsFind(int cur, int x, int y) {
	int find = 0;
	
	// basecase
	if (word.length() == cur) return 1;		// 단어의 마지막 문자에 도달했을 때
	if (memory[cur][x][y] == 1) return 0;	// 이미 해당 문자 상하좌우/대각선에는 다음 문자가 없는 것이 확인되었을 때

	// 반복문을 사용해 상하좌우/대각선 확인
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i == 0 && j == 0) || (x + i < 0) || (x + i > 4) || (y + j < 0) || (y + j > 4)) continue;
			if (word[cur] == map[x + i][y + j]) {			// 다음 문자가 있을 경우
				find = IsFind(cur + 1, x + i, y + j);		// 그 다음 문자 확인을 위해 재귀 호출

				// 단어가 게임판에 존재함을 확인했을 때
				if (find == 1 && cur == word.length() - 1) return 2;	
				if (find == 2) return 2;								
			}
		}
	}
	if (find == 0) memory[cur][x][y] = 1;
	return find;
}

// 해당되는 단어가 게임판에 존재하는지 확인하는 함수
void IsinWord() { 
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (word[0] == map[x][y] ){
				if (IsFind(1, x, y) == 2) {
					cout << word << " " << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << word << " " << "NO" << endl;
}

int main() {
	

	cin >> N;
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> map[i][j];
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			memset(memory, 0, sizeof(memory));
			cin >> word;
			IsinWord();
		}
		if ((--N) == 0) break;
	}
}




