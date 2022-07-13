#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

extern void init();
extern int add(int mId, int mGrade, char mGender[7], int mScore);
extern int remove(int mId);
extern int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore);

typedef struct student {
	int mId;
	int mGrade;
	char mGender[7];
	int mScore;

}student;

typedef struct node {
	student st;
	node* next;
	node* prev;
}node;

node* head, * lear;

void init() {
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	head->prev = NULL;
	lear = head;
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
	student tmp;
	tmp.mId = mId;
	tmp.mGrade = mGrade;
	strcpy(tmp.mGender, mGender);
	tmp.mScore = mScore;

	node* n = (node*)malloc(sizeof(node));
	n->st = tmp;

	if (head->next == NULL) {
		n->prev = head;
		n->next = NULL;
		head->next = n;
		lear = n;
		return mId;
	}

	int flag = 0;
	node* p;
	node* pprev;
	node* psave = NULL;
	for (p = head->next; p != NULL; p = p->next) {
		psave = p;
		pprev = p->prev;
		if (p->st.mScore < mScore) {
			pprev->next = n;
			n->prev = pprev;
			p->prev = n;
			n->next = p;
			flag = 1;
			break;
		}
		else if (p->st.mScore == mScore) {
			if (p->st.mId < mId) {
				pprev->next = n;
				n->prev = pprev;
				p->prev = n;
				n->next = p;
				flag = 1;
				break;
			}
		}
	}
	if (!flag) {
		psave->next = n;
		n->prev = psave;
		n->next = NULL;
		lear = n;
	}


	for (p = head->next; p != NULL; p = p->next) {
		if (p->st.mGrade == mGrade && !strcmp(mGender, p->st.mGender)) {
			return p->st.mId;
		}
	}
}

int remove(int mId) {

	node* p, * psave = NULL;
	for (p = head->next; p != NULL; p = p->next) {
		if (p->st.mId == mId) {
			psave = p;
			break;
		}
	}
	if (psave == NULL) return 0;

	int cur_grade = psave->st.mGrade;
	char cur_gender[7];
	strcpy(cur_gender, psave->st.mGender);

	psave->prev->next = psave->next;
	if (psave->next != NULL) psave->next->prev = psave->prev;
	else {
		lear = psave->prev;
	}

	for (p = lear; p != head; p = p->prev) {
		if (p->st.mGrade == cur_grade && !strcmp(cur_gender, p->st.mGender)) {
			return p->st.mId;
		}
	}

	return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	node* p, * psave;

	if (head->next->st.mScore < mScore) return 0;

	for (p = lear; p != head; p = p->prev) {
		if (p->st.mScore < mScore) continue;

		int flag = 0;
		for (int j = 0; j < mGradeCnt; j++) {
			if (p->st.mGrade == mGrade[j]) {
				flag = 1; break;
			}
		}
		if (!flag) continue;

		flag = 0;
		for (int j = 0; j < mGenderCnt; j++) {
			if (!strcmp(mGender[j], p->st.mGender)) {
				flag = 1; break;
			}
		}
		if (!flag) continue;

		return p->st.mId;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_QUERY 400

static bool run() {
	int q;
	scanf("%d", &q);

	int id, grade, score;
	char gender[7];
	int cmd, ans, ret;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case CMD_INIT:
			init();
			okay = true;
			break;
		case CMD_ADD:
			scanf("%d %d %s %d %d", &id, &grade, gender, &score, &ans);
			ret = add(id, grade, gender, score);
			if (ans != ret)
				okay = false;
			break;
		case CMD_REMOVE:
			scanf("%d %d", &id, &ans);
			ret = remove(id);
			if (ans != ret)
				okay = false;

			break;
		case CMD_QUERY: {
			int gradeCnt, genderCnt;
			int gradeArr[3];
			char genderArr[2][7];
			scanf("%d", &gradeCnt);
			if (gradeCnt == 1) {
				scanf("%d %d", &gradeArr[0], &genderCnt);
			}
			else if (gradeCnt == 2) {
				scanf("%d %d %d", &gradeArr[0], &gradeArr[1], &genderCnt);
			}
			else {
				scanf("%d %d %d %d", &gradeArr[0], &gradeArr[1], &gradeArr[2], &genderCnt);
			}
			if (genderCnt == 1) {
				scanf("%s %d %d", genderArr[0], &score, &ans);
			}
			else {
				scanf("%s %s %d %d", genderArr[0], genderArr[1], &score, &ans);
			}

			ret = query(gradeCnt, gradeArr, genderCnt, genderArr, score);
			if (ans != ret)
				okay = false;
			break;
		}
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}