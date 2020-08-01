#include <iostream>
#include <cstring>
using namespace std;
/*------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >
 
		★□□□□		예를들어 2X5 크기의 사각형이 있으면
		□□□□□		★ 위치부터 시작해서,

	1) ■□□□□		2) ■■□□□
	   ■□□□□          □□□□□

	   이 두가지 경우로 만들 수 있는 방법의 수 합산
	   1의 경우에는 첫번째줄의 세번째 칸으로 인덱스 이동해서 똑같이 1 & 2번 반복
	   2의 경우에는 첫번째줄의 두번째 칸으로 인덱스 이동해서 똑같이 1 & 2번 반복

	   인덱스가 첫번째줄의 맨 끝에 도달하면 방법 수 +1

	memorization : 현재 인덱스 위치까지의 방법 수 캐시에 저장

	4ms

-------------------------------------------------------------------------------------------*/
int cache[2][100];
int s; 

int CountRec(int y, int x, int rec[][100]) {
	int sum = 0, tmprec[2][100];
	if (x > s - 1) return 0;	// base case

	int &ret = cache[y][x];			// memorization
	if (ret != -1) return ret;	

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < s; j++) 
			tmprec[i][j] = rec[i][j];	
	if (rec[y + 1][x] == 0) { // case 1
		tmprec[y][x] = tmprec[y + 1][x] = 1;
		if (x == s - 1) sum = 1;
		else sum = CountRec(y, x + 1, tmprec);
	}
	if (x + 1 < s) {					// case 2
		if (rec[y][x + 1] == 0) {
			rec[y][x] = rec[y][x + 1] = 1;
			if (x + 1 == s - 1)	return ret = (sum + 1) % 1000000007;
			else sum += CountRec(y, x + 2, rec);
		}
	}
	return ret = sum % 1000000007;
}

int main() {
	int n, rec[2][100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(cache, -1, sizeof(cache));
		memset(rec, 0, sizeof(rec));
		cin >> s;
		cout << CountRec(0, 0, rec) << endl;
	}
	return 0;
}