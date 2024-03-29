#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string::iterator it = s.begin();
		s = reverse(it);
		cout << s << endl;
	}
	return 0;
}