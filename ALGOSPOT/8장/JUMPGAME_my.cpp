#include <iostream>
#include <cstring>
using namespace std;

/*------------------------------------------------------------------------------------------

		< 내가 생각한 알고리즘 >

  memorization : 오른쪽/아래로 지나간 적 있는지 여부를 기억하는 Right, Down
  해당 위치를 해당 방향으로 지나갈 경우 값 +1 해서 표시 -> 이동한 적 없는 경로로만 이동

  32ms

-------------------------------------------------------------------------------------------*/

int Right[100][100] = { 0 };
int Down[100][100] = { 0 };

int JumpCheck(int map[][100], int y, int x, int size) {
	int ret1, ret2;
	// base case : size 초과 혹은 끝지점 도달
	if (y == size - 1 && x == size - 1) return 1;
	if (y > size - 1 || x > size - 1) return -1;
	
	// 현재 위치에서 오른쪽, 아래쪽으로 모두 한번이라도 이동한 적 있을 때
	if (Right[y][x] != 0 && Down[y][x] != 0) return -1;
	// 현재 위치에서 오른쪽으로 이동한 적 없을 경우
	if (Right[y][x] == 0) {
		Right[y][x]++;
		ret1 = JumpCheck(map, y, x + map[y][x], size);
	}
	// 현재 위치에서 아래쪽으로 이동한 적 없을 경우
	if (Down[y][x] == 0) {
		Down[y][x]++;
		ret2 = JumpCheck(map, y + map[y][x], x, size);
	}

	// result
	if (ret1 == 1 || ret2 == 1) return 1;
	else return -1;
}
int main() {
	int n, m, map[100][100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				cin >> map[j][k];
		if (JumpCheck(map, 0, 0, m)==1) cout << "YES" << endl;
		else cout << "NO" << endl;
		memset(Right, 0, sizeof(Right));
		memset(Down, 0, sizeof(Down));
	}
	return 0;
}
