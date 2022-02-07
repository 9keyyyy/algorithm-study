// 2022-02-08 BOJ 10799
// stack
// 규칙 찾기
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<int> st;
	int num = 0;
	
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') 
			st.push(str[i]);
		// ')' 일 때
		else {	
			// 이전에 '('가 있었다면 레이저를 제외한 '('의 개수가 막대의 개수임
			if (str[i-1] == '(') {	
				st.pop();
				num += st.size();
			}
			// 이전에 ')'가 있었다면 막대 종료 -> 마지막으로 남은 부분 +1
			else {					
				st.pop();
				num++;
			}
		}
	}
	cout << num;
	return 0;
}