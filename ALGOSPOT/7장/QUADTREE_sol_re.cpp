// 분할 정복
// 8ms
#include <iostream>
#include <iterator>
using namespace std;

int C;
string image;

string Quadtree(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') return string(1, head);

	string upL = Quadtree(it);
	string upR = Quadtree(it);
	string lowL = Quadtree(it);
	string lowR = Quadtree(it);

	return "x" + lowL + lowR + upL + upR;
}
int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> image;
		string::iterator start = image.begin();
		cout << Quadtree(start) << endl;

	}
}