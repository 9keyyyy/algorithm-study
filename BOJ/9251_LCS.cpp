// 22.01.04 BOJ 9251 LCS
// 동적 계획법
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int cache[1001][1001];
string str1, str2;

void LCS() {
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
		}
	}
	cout << cache[str1.length()][str2.length()];
}

// 시간초과 ver
int LCS1(int s1, int s2) {
	int& ret = cache[s1][s2];
	if (ret != -1) return ret;

	if (str1[s1] == str2[s2]) ret = 1;
	else ret = 0;

	for (int next = s1 + 1; next < str1.length(); next++) {
		for (int nnext = s2 + 1; nnext < str2.length(); nnext++) {
			if (str1[next] == str2[nnext]) {
				ret = max(ret, LCS1(next, nnext) + 1);
			}
		}
	}
	return ret;
}

int main() {
	memset(cache, 0, sizeof(cache));
	cin >> str1 >> str2;
	LCS();
	/*
	* 시간초과 ver
	* 
	int maxLen = 0;
	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++)
			maxLen = max(maxLen, LCS(i, j));
	}
	cout << maxLen;
	*/
	
	return 0;
}