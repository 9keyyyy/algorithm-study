#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*---------------------------------------------------------------------------

	... 시간초과 ...

	<  생각한 알고리즘  >
	팬 배열을 아이돌 배열의 2배보다 작아질때까지 계속 반으로 나누어 계산..
	쪼개진 배열들에서 sum값 계산해 재귀로 계속 합산...

	FENCE sol 보고 생각나서 해봤는데,
	결과적으로 처음부터 순회하는 거랑 다를바 없음...

----------------------------------------------------------------------------*/


int AllHug(char *idol, char *fan, int left, int right) {
	int sum = 0, idolsize = strlen(idol);
	if (idolsize * 2 > (right - left + 1)) {
		for (int i = left; i <= right - idolsize + 1; i++) {
			int len = 0, flag = 0;
			for (int j = i; j < i + strlen(idol); j++) {
				if (idol[len++] == 'M' && fan[j] == 'M') {
					flag = 1;
				}
			}
			if (flag == 0) sum += 1;
		}
	}
	else {
		int mid = (right - left) / 2;
		sum += AllHug(idol, fan, left, mid) + AllHug(idol, fan, mid + 1, right);
		for (int i = mid + 1; i != mid + idolsize; i++) {
			int len = idolsize - 1, flag = 0;
			for (int j = i; j > i - strlen(idol); j--) {
				if (idol[len--] == 'M' && fan[j] == 'M') {
					flag = 1;
				}
			}
			if (flag == 0) sum += 1;
		}
	}
	return sum;
}

int main() {
	int n;
	char fan[200001], idol[200001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> idol;
		cin >> fan;
		cout << AllHug(idol, fan, 0, strlen(fan) - 1) << endl;
	}
	return 0;
}
