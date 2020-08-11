#include <iostream>
#include <string>
#include  <stack>
using namespace std;
/*---------------------------------------------------------

		< 내가 생각한 알고리즘 >
	
	C++ STL stack 이용
	'(' '[' '{' 일 때 stack에 push
	')' ']' '}' 일 때 stack에서 top 확인 & pop

	16ms
	
---------------------------------------------------------*/
stack<char> s;
int Compare(char a, char b) {
	s.pop();
	if (a == ')') return (b == '(');
	else if (a == ']') return (b == '[');
	else if (a == '}') return (b == '{');
}
int Check(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (s.empty() || Compare(str[i], s.top()) == 0) return 0; 
		}
	}
	if (s.empty()) return 1; 
	else return 0; 
}
int main() {
	int n;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (Check(str) == 1) cout << "YES\n";
		else cout << "NO\n";
		while (!s.empty()) s.pop();
	}
}
