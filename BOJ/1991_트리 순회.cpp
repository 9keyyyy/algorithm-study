// 20220517
// tree
using namespace std;
#include <iostream>

int n;
pair<int, int> edge[26];

void preorder(char c) {
	if (c == '.') return;
	cout << c;
	preorder(edge[c - 'A'].first);
	preorder(edge[c - 'A'].second);
}
void inorder(char c) {
	if (c == '.') return;
	inorder(edge[c - 'A'].first);
	cout << c;
	inorder(edge[c - 'A'].second);
}
void postorder(char c) {
	if (c == '.') return;
	postorder(edge[c - 'A'].first);
	postorder(edge[c - 'A'].second);
	cout << c;
}
int main() {
	char c, r, l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> l >> r;
		edge[c - 'A'] = make_pair(l, r);
	}

	//for (int i = 0; i < n; i++) {
	//	printf("%c %c %c\n", i + 'A', edge[i].first, edge[i].second);
	//}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";
}