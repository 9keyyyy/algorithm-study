#include <string>
#include <iostream>
using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

int inRange(int y, int x) {
	if (0 <= y && y <= 4 && 0 <= x && x <= 4) return 1;
	else return 0;
}
bool hasWord(int y, int x, const string& word, char **str) {
	//printf("[%c]", str[y][x]);
	if (!inRange(y, x)) return false;
	if (str[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word.substr(1), str)) return true;
	}
	return false;
}

int main() {

	int m, n, cnt = 0, x = 0, y = 0;
	char **str;
	string word;

	str = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 5; i++) {
		str[i] = (char *)malloc(sizeof(char) * 5);
	}
	cin >> m; getchar();
	while (1) {
		int flag = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) cin >> str[i][j];
			getchar();
		}
		/*
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) cout << str[i][j];
			cout << endl;
		}
		*/
		cin >> n; getchar();
		for (int i = 0; i < n; i++) {
			flag = 0;
			cin >> word;
			//cout << in << endl;
			for (int j = 0; j < 5; j++) {
				for (int l = 0; l < 5; l++) {
					if (hasWord(j, l, word, str)) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				cout << word;
				printf(" NO\n");
			}
			else {
				cout << word;
				printf(" YES\n");
			}
		}
		cnt++;
		if (cnt == m) break;
	}

	return 0;
}