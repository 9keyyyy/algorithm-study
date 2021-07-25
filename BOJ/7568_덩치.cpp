// ¿ÏÀü Å½»ö
// 0ms
#include <iostream>
using namespace std;

int main(){
	int N, data[50][2], rank[50];
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data[i][0] >> data[i][1];
	}

	for (int i = 0; i < N; i++) {
		rank[i] = 1;
		for (int j = 0; j < N; j++) {
			if (data[i][0] < data[j][0] && data[i][1] < data[j][1]) rank[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << rank[i] << " ";
	}
}