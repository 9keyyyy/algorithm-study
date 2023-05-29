//
//  14940_쉬운 최단거리.cpp
//  cpp
//
//  Created by Gukhee Jo on 5/29/23.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int graph[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void bfs(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
        
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] == 0 && graph[ny][nx] == 1){
                visited[ny][nx] = 1;
                graph[ny][nx] = graph[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

}

int main(){
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
            if (graph[i][j] == 2){
                graph[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    
    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (visited[i][j] == 0 && graph[i][j] == 1) graph[i][j] = -1;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
