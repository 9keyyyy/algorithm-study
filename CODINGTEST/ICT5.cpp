#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


void superStack(vector <string> operations) {
    
    string word;
    vector<int> array;
    for (int i = 0; i < operations.size(); i++) {
        vector<string> arr;
        istringstream ss(operations[i]);
        while (getline(ss, word, ' ')) 
            arr.push_back(word);
        if (arr[0] == "push") {
            array.push_back(stoi(arr[1]));
            cout << arr[1] << endl;
        }
        else if (arr[0] == "inc") {
            for (int j = 0; j < stoi(arr[1]); j++) {
                array[j] += stoi(arr[2]);
            }
            cout << array[array.size() - 1] << endl;
        }
        else if (arr[0] == "pop") {
            if (array.size() == 0) cout << "EMPTY" << endl;
            array.erase(array.begin() + array.size() - 1);
            if (array.size() == 0) cout << "EMPTY" << endl;
            else cout << array[array.size() - 1] << endl;
        }
    }
}


int main()
{
    int n;

    cin >> n;
    string s;
    vector<string> arr;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        arr.push_back(s);
    }
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
    superStack(arr);

    return 0;
}
