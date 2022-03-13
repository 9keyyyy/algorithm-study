
// 20220311 BOJ 1707 이분 그래프
// DFS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;   // 방문했는지
vector<int> flag;       // 색깔
string result;


int returnNextFlag(int flag) {
    if (flag == 0) flag = 1;
    else flag = 0;
    return flag;
}

void dfs(int here, int flg) {
    if (visited[here] || result == "NO") return;
    visited[here] = true;
    flag[here] = flg;
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (!visited[there]) {
            dfs(there, returnNextFlag(flg));
        }
        else {
            if (flag[there] == flg) {
                result = "NO";
                return;
            }
        }
    }
}
void dfsAll() {
    visited = vector<bool>(adj.size(), false);
    flag = vector<int>(adj.size(), -1);

    int firstflag = 0;
    for (int i = 1; i < adj.size(); i++) {
        if (!visited[i]) {
            dfs(i, firstflag);
            firstflag = returnNextFlag(firstflag);
        }
    }
}

int main() {
    int K, N, M, s, e;
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> N >> M;
        adj = vector<vector<int>>(N + 1);
        result = "YES";
        for (int j = 0; j < M; j++) {
            cin >> s >> e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        dfsAll();
        cout << result << endl;
    }

    return 0;
}