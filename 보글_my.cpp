#include <iostream>
using namespace std;

int has(char *in, char **str) {
	int k = 0;
	int ti, tj;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[i][j] == in[k]) {
				//printf("[%d %d]", i, j);
				//printf("[%c]", str[i - 1][j]);
				ti = i;
				tj = j;
				k++;
				while (1) {
					//printf("[%c]", in[k]);
					//printf("[%d %d]", i, j);
					int flag = 0;
					int flag1 = 0;
					if (i > 0 && j > 0 && flag1 == 0) {
						if (str[i - 1][j - 1] == in[k]) {
							//printf("%c", str[i - 1][j - 1]);
							i = i - 1;
							j = j - 1;
							k++;
							flag = 1; flag1 = 1;
						}
					}
					if (i > 0 && flag1 == 0) {
						if (str[i - 1][j] == in[k] ) {
							//printf("%c", str[i - 1][j]);
								i = i - 1;
								k++;
								flag = 1;
								flag1 = 1;
						}
					}
					if (i > 0 && j < 4 && flag1 == 0) {
						if (str[i - 1][j + 1] == in[k]) {
							//printf("%c", str[i - 1][j + 1]);
								i = i - 1;
								j = j + 1;
								k++;
								flag = 1;
								flag1 = 1;

						}
					}
					if (j > 0 && flag1 == 0) {
						if (str[i][j - 1] == in[k]) {
							//printf("%c", str[i][j - 1]);

								j = j - 1;
								k++;
								flag = 1;
								flag1 = 1;
						}
					}
					if (j < 4 && flag1 == 0) {
						if (str[i][j + 1] == in[k]) {
							//printf("%c", str[i][j + 1]);
								j = j + 1;
								k++;
								flag = 1;
								flag1 = 1;

						}
					}
					if (i < 4 && j > 0 && flag1 == 0) {
						if (str[i + 1][j - 1] == in[k]) {
							//printf("%c", str[i + 1][j - 1]);
								i = i + 1;
								j = j - 1;
								k++;
								flag = 1; flag1 = 1;
						}
					}
					if (i < 4 && flag1 == 0) {
						//printf("((%c))", str[i + 1][j]);
						if (str[i + 1][j] == in[k]) {
							//printf("%c", str[i + 1][j]);
							i = i + 1;
							k++;
							flag = 1; flag1 = 1;
						}
					}
					if (i < 4 && j < 4 && flag1 == 0) {
						if (str[i + 1][j + 1] == in[k]) {
							//printf("%c", str[i + 1][j + 1]);
							i = i + 1;
							j = j + 1;
							k++;
							flag = 1;
							flag1 = 1;

						}
					}
					//printf("(f : %d)\n", flag);
					if (flag == 0) break;
				}
				if (in[k] == '\0') return 1;
				i = ti;
				j = tj;
				k = 0;
			}
		}
	}
	return 0;
}

int main() {
	int m, n, cnt = 0;
	char **str;
	char in[11];

	str = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 5; i++) {
		str[i] = (char *)malloc(sizeof(char) * 5);
	}
	cin >> m; getchar();
	while (1) {
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
			cin >> in;
			//cout << in << endl;
			if (has(in, str)) {
				printf("%s", in);
				printf(" YES\n");
			}
			else {
				printf("%s", in);
				printf(" NO\n");
			}
		}
		cnt++;
		if (cnt == m) break;
	}

	return 0;
}