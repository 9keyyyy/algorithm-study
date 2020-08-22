#include <iostream>
using namespace std;



// 트립의 노드를 표현하는 객체 구현
typedef int KeyType;
struct Node {
	KeyType key; // 노드에 저장된 원소
	int priority, size; // 우선순위, 서브트리 크기
	Node *left, *right; // 두 자식노드 포인터
	// 난수 우선순위 생성, 그 외 값들 초기화
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){}
	void setLeft(Node *newLeft) { left = newLeft; calcSize(); }
	void setRight(Node *newRight) { right = newRight; calcSize(); }
	// size 갱신
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};



// 트립에서 노드 추가와 트립 쪼개기 연산 구현
typedef pair<Node*, Node*> NodePair;
// root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 같는 두개의 트립으로 분리
NodePair split(Node *root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) { // root가 key 미만이면 오른쪽 서브트리 쪼갬
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	// root가 key이상이면 왼쪽 서브트리 쪼갬
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
// root를 루트로 하는 트립에 새 노드를 삽입한뒤 결과 트립의 루트 반환
Node* insert(Node* root, Node *node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}
// root = insert(root, new Node(value)); -> 트리에 새로운 값 value 추가



// 노드의 삭제와 합치기 연산의 구현
Node* merge(Node *a, Node *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}
Node *erase(Node* root, KeyType key) {
	if (root == NULL) return root;
	if (root->key == key) {
		Node *ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}




// k번째 원소 찾기
// 왼쪽 서브트리 크기 l이라고 할때,
// k<=l : k번째 노드는 왼족 서브트리에 속해있음
// k=l+1 : 루트가 k번째 노드
// k>l+1 : k번째 노드는 오른쪽 서브트리에서 k-l-1번째 노드
Node* kth(Node *root, int k) {
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}




// 트립에서 X보다 작은 원소의 수 찾는 알고리즘
int countLessThan(Node *root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}
int main() {
	return 0;
}