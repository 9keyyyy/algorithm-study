#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct student {
    int mId;
    int mGrade;
    char mGender[7];
    int mScore;
}student;

vector<student> st;

void init() {
    st.clear();
    return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    student tmp;
    tmp.mId = mId;
    tmp.mGrade = mGrade;
    strcpy(tmp.mGender, mGender);
    tmp.mScore = mScore;

    if (st.size() == 0) {
        st.push_back(tmp);
        return mId;
    }

    int flag = 0;
    for (int i = 0; i < st.size(); i++) {
        if (st[i].mScore < mScore) {
            st.insert(st.begin() + i, tmp);
            flag = 1;
            break;
        }
        else if (st[i].mScore == mScore) {
            if (st[i].mId < mId) {
                st.insert(st.begin() + i, tmp);
                flag = 1;
                break;
            }
        }
    }
    if (!flag) st.push_back(tmp);

    for (int i = 0; i < st.size(); i++) {
        if (st[i].mGrade == mGrade && !strcmp(mGender, st[i].mGender)) {
            return st[i].mId;
        }
    }
}

int remove(int mId) {
    int idx = st.size();
    for (int i = 0; i < st.size(); i++) {
        if (st[i].mId == mId) {
            idx = i;
            break;
        }
    }
    if (idx == st.size()) return 0;

    int cur_grade = st[idx].mGrade;
    char cur_gender[7];
    strcpy(cur_gender, st[idx].mGender);
    st.erase(st.begin() + idx);

    for (int i = st.size() - 1; i >= 0; i--) {
        if (st[i].mGrade == cur_grade && !strcmp(cur_gender, st[i].mGender)) {
            return st[i].mId;
        }
    }

    return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    for (int i = st.size() - 1; i >= 0; i--) {
        if (st[i].mScore < mScore) continue;

        int flag = 0;
        for (int j = 0; j < mGradeCnt; j++) {
            if (st[i].mGrade == mGrade[j]) flag = 1;
        }
        if (!flag) continue;

        flag = 0;
        for (int j = 0; j < mGenderCnt; j++) {
            if (!strcmp(mGender[j], st[i].mGender)) flag = 1;
        }
        if (!flag) continue;

        return st[i].mId;
    }

    return 0;
}