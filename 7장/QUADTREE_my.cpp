#include <iostream>
#include <cstring>
using namespace std;

/*------------------------------------------------------------------------------------------
							
		                        	<	전체적인 알고리즘	>

  입력값에 따른 트리 만듬 -> 트리 순회하면서 연결링크를 바꾸어 상하반전 -> 트리 순회 -> 끝!

  * 참고
	- 트리는 연결리스트를 사용해 구현
	- 'x'노드 아래에만 자식 노드가 있다는 특징
	  !!! 'x'노드의 경우 자식이 4명 -> 하나만 child로 하고 나머지는 sibling으로 연결 !!!
	- 노드의 n값은 'x'노드의 자식 개수 -> 4가 되었을 시 다음 sibling으로 이동

 -------------------------------------------------------------------------------------------*/

// 트리의 노드
typedef struct node {		
	char color;
	int n;
	struct node *child;
	struct node *parent;
	struct node *sibling;
}NODE;

// 노드 생성
NODE *getnode(char color) {
	NODE *p = (NODE *)malloc(sizeof(NODE));
	p->color = color;
	p->child = NULL;
	p->parent = NULL;
	p->sibling = NULL;
	return p;
}

// 트리 생성 
// 노드생성은 'x'노드를 기준으로 이루어짐
void MakeTree(char *q, NODE *t) {
	// base case : 문자열 끝
	if (*q == '\0') return;	
	// 자식이 4개가 되면 부모노드로 이동
	else if (t->n == 4) MakeTree(q, t->parent);
	// 문자가 'x'일 때
	else if (*q == 'x') {
		NODE *p = getnode('x');
		// 첫번째 자식일 경우 : child
		if (t->n == 0) t->child = p;
		// 그 외의 경우 : child에서 sibling으로 연결
		// 가장 마지막 sibling의 다음으로 연결
		else {
			NODE *r = t->child;	
			while (r->sibling != NULL) {
				r = r->sibling;
			}
			r->sibling = p;
		}		
		p->n = 0;			// 자식노드(현재 생성한 노드)의 자식은 0
		p->parent = t;
		t->n += 1;			// 부모노드의 자식 +1
		MakeTree(++q, p);	// 자식노드(현재 생성한 노드)로 넘겨줌
	}
	// 문자가 'w' or 'b'일 때
	else if (*q == 'w' || *q == 'b') {
		NODE *p = getnode(*q);
		if (t->n == 0) t->child = p;
		else {
			NODE *r = t->child;
			while (r->sibling != NULL) {
				r = r->sibling;
			}
			r->sibling = p;
		}
		p->parent = t;
		t->n += 1;
		MakeTree(++q, t);	// 부모노드로 넘겨줌
	}
}

// 트리 순회
// 전체 sibling을 순회하면서, 'x'노드일 경우 child 인자 넘겨 재귀 호출
void TraverseTree(NODE *t) {
	while (t != NULL) {
		cout << t->color;
		if (t->color == 'x') {
			TraverseTree(t->child);
		}
		t = t->sibling;
	}	
}

// 그림 상하 반전( 12, 34 위치 변경 )
// 트리 순회와 동일한 방식 -> 연결링크 변경
void ReverseTree(NODE *t) {
	while (t != NULL) {
		if (t->color == 'x') {
			NODE *pchild = t->child;
			t->child = t->child->sibling->sibling;
			pchild->sibling->sibling = NULL;
			t->child->sibling->sibling = pchild;
			ReverseTree(t->child);
		}
		t = t->sibling;
	}
}
int main() {
	int n;
	char s[1001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (strcmp(s, "w") == 0 || strcmp(s, "b") == 0) cout << s << endl;
		else {
			NODE *root = NULL;
			NODE *t = getnode('x');
			t->n = 0;
			root = t;
			MakeTree(s+1, t);
			ReverseTree(root);
			TraverseTree(root);
			cout << endl;
		}
	}
	return 0;
}
