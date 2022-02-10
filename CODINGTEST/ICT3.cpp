// 20220210
// 7/13
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


/*
 * Complete the 'calculateCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER threshold
 */

int calculateCost(vector<int> arr, int threshold) {
    int totalMin = 500000000;
    for (int t = 1; t <= threshold; t++) {
        for (int i = 1; i <= t; i++) {
            int idx = 0;
            int maxSum = 0;
            int max = arr[0];
            for (idx = 0; idx < i; idx++) {
                if (arr[idx] > max) max = arr[idx];
            }
            maxSum += max;
            int tmp = idx % t;
            while (idx < arr.size()) {
                max = arr[idx++];
                while (idx % t != tmp && idx < arr.size()) {
                    if (max < arr[idx]) max = arr[idx];
                    idx++;
                }
                maxSum += max;
            }
            if (totalMin > maxSum) totalMin = maxSum;
        }
    }
    return totalMin;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    int result = calculateCost(arr, threshold);

    fout << result << "\n";

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


