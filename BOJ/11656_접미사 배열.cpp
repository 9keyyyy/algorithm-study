// 2022-02-08
// string, sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
vector<string> arr;
int main() {
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		arr.push_back(str.substr(i));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < str.length(); i++) {
		cout << arr[i] << "\n";
	}
}