// 2022-02-08
#include <iostream>
using namespace std;

int main() {
	int m, d, sum = 0;
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	cin >> m >> d;
	
	for (int i = 0; i < m - 1; i++) {
		sum += day[i];
	}
	sum += d;
	cout << week[sum % 7];
	return 0;
}