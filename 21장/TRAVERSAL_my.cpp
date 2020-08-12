#include <iostream>
using namespace std;
/*----------------------------------------------------------------------------------------------------------

	< 내가 생각한 알고리즘 >

	연결리스트를 이용한 트리 구현
	전위 순회, 중위 순회 값을 바탕으로 트리 생성 -> 후위 순회하며 출력

	1. 전위 순회에서는 첫번째 원소가 root가 됨
	2. 중위 순회에서는 root 원소가 나올때까지의 원소들 모두 root를 기준으로 왼쪽 세부트리에 해당하고
	   root 원소 이후의 원소들은 오른쪽 세부트리에 해당함

	위의 특징을 이용해서 root 원소를 기준으로 왼쪽/오른쪽 세부트리를 재귀를 통해 계속 만듬
	
	idx에 중위순회에서의 root 위치를 저장해 이를 기준으로 왼쪽/오른쪽 트리 나누고,
	원소가 1 혹은 2가 될때를 basecase로 설정해 한쪽으로 편중된 트리일 경우 처리

	4ms

-----------------------------------------------------------------------------------------------------------*/
typedef struct node { // Tree 구조체
	int e;
	struct node* right;
	struct node* left;
}NODE;
NODE *getnode(int e) {	// node 생성
	NODE *p = (NODE *)malloc(sizeof(NODE));
	p->e = e;
	p->right = NULL;
	p->left = NULL;
	return p;
}
NODE *MakeTree(int *A, int *B, int n) {	// Tree 만드는 함수
	int idx = 0;
	for (int i = 0; i < n; i++)
		if (B[i] == A[0]) idx = i;

	NODE *root = getnode(A[0]);
	// basecase
	if (n == 1) return root;
	if (n == 2) {
		if (A[0] == B[0]) root->right = getnode(A[1]);
		else if (A[0] == B[1]) root->left = getnode(A[1]);
		return root;
	}

	if (idx != 0) root->left = MakeTree(A + 1, B, idx);
	if (idx != n - 1) root->right = MakeTree(A + idx + 1, B + idx + 1, n - idx - 1);
	return root;
}
void postorder(NODE *p) {	// 후위 순회
	if (p == NULL) return;
	postorder(p->left);
	postorder(p->right);
	cout << p->e << " ";
}

int main() {
	int A[100], B[100], n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) cin >> A[j];
		for (int j = 0; j < m; j++) cin >> B[j];
		NODE *root = MakeTree(A, B, m);
		postorder(root); cout << endl;
	}
	return 0;
}
