// 20221002 BOJ 10610 30
// Greedy

// long long 보다 큰 수 => string 사용해야함
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> arr;
string str;

void sol() {
	int flag = 0, total = 0;

	for (int i = 0; i < str.length(); i++) {
		int e = str[i] - '0';
		if (e == 0) flag = 1;
		total += e;
	}
	
	if (total % 3 == 0 && flag == 1) {
		sort(str.begin(), str.end(), greater<>());
		cout << str;
	}
	else cout << -1;
}

int main() {
	cin >> str;

	sol();
}
