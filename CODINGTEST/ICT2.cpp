// 20220210
// 13/13
#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'getSubstringCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int getSubstringCount(string s) {
    int num1max = 0;
    int num0max = 0;
    for (int i = 0; i < s.length(); i++) {
        int num = 0;
        int idx = i, ifix = i;
        if (s[i] == '1') {
            while (idx <= s.length() && s[idx++] == '1') {
                num++;
            }
            i = idx - 2;
            idx = ifix - 1;
            while (idx >= 0 && num > 0 && s[idx--] == '0')
            {
                num1max++;
                num--;
            }
        }
        else if (s[i] == '0') {
            while (idx <= s.length() && s[idx++] == '0') {
                num++;
            }
            i = idx - 2;
            idx = ifix - 1;
            while (idx >= 0 && num > 0 && s[idx--] == '1')
            {
                num0max++;
                num--;
            }
        }
    }
    return num1max + num0max;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = getSubstringCount(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
