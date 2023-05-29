// 230529

#include <iostream>
#include <vector>
using namespace std;

int n, v;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int idx){
    visited[idx] = 1;
    for(int i=0;i<graph[idx].size();i++){
        if (visited[graph[idx][i]] == 0) dfs(graph[idx][i]);
    }
}

int main() {
    cin >> n >> v;
    
    visited = vector<int> (n+1, 0);
    graph = vector<vector<int>> (n+1);
    int s, e;
    
    for(int i = 0;i < v; i++){
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    dfs(1);
    
    int total = 0;
    for (int i=1;i<=n;i++){
        if (visited[i] == 1) total++;
    }
    
    cout << total - 1;
    
}
