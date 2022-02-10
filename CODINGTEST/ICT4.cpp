// 20220210 
// 12/13
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


/*
 * Complete the 'findSchedules' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER workHours
 *  2. INTEGER dayHours
 *  3. STRING pattern
 */

vector<string> arr;

void decompose(stack<int> st, int cnt, int dayH) {
    while (true) {
        stack<int> t = stack<int>(st);
        if (t.size() <= cnt) {
            string s;
            int flag = 0;
            for (int i = 0; i < st.size(); i++) {
                if (t.top() > dayH) flag = 1;
                s += to_string(t.top());
                t.pop();
            }
            if (flag == 0) {
                while (s.length() < cnt) {
                    s += "0";
                }
                arr.push_back(s);
            }
        }

        int tmp = st.top();
        if (tmp == 0) break;
        st.pop();
        if (tmp != 1) {
            st.push(tmp - 1);
            st.push(1);
        }
        else {
            int sum = 2;
            for (; !st.empty() && st.top() == 1; st.pop()) {
                sum++;
            }
            if (st.empty()) break;
            int pivot = st.top() - 1;
            st.pop();
            st.push(pivot);
            while (sum > pivot) {
                st.push(pivot);
                sum -= pivot;
            }
            st.push(sum);
        }
    }
}
vector<string> findSchedules(int workHours, int dayHours, string pattern) {
    vector<string> final;
    int position[7][2], r = 0;
    int day[7], cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (pattern[i] == '?') {
            day[i] = -1;
            cnt++;
        }
        else {
            day[i] = pattern[i] - '0';
            workHours -= day[i];
            position[r][0] = i;
            position[r++][1] = day[i];
        }
    }
    stack<int> st;
    st.push(workHours);
    decompose(st, cnt, dayHours);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        string temp = arr[i];
        sort(temp.begin(), temp.end());
        do {

            string temp1 = temp;
            for (int j = 0; j < r; j++) {
                temp1.insert(position[j][0], to_string(position[j][1]));
            }
            final.push_back(temp1);

        } while (next_permutation(temp.begin(), temp.end()));
    }

    final.erase(unique(final.begin(), final.end()), final.end());
    sort(final.begin(), final.end());

    return final;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string workHours_temp;
    getline(cin, workHours_temp);

    int workHours = stoi(ltrim(rtrim(workHours_temp)));

    string dayHours_temp;
    getline(cin, dayHours_temp);

    int dayHours = stoi(ltrim(rtrim(dayHours_temp)));

    string pattern;
    getline(cin, pattern);

    vector<string> result = findSchedules(workHours, dayHours, pattern);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}



