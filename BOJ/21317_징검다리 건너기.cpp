//
//  21317_징검다리 건너기.cpp
//  DP
//
//  Created by Gukhee Jo on 5/30/23.
//

#include <iostream>
using namespace std;

int n, k;
int rock[2][21];
int cache[21][2];

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> rock[0][i] >> rock[1][i];
    }
    cin >> k;
    
    for(int i = 0; i < 4; i++){
        cache[i][1] = 999999;
    }
    
    cache[1][0] = 0;
    cache[2][0] = rock[0][1];
    cache[3][0] = min(rock[0][1] + rock[0][2], rock[1][1]);
    
    for(int i = 4; i <= n; i++){
        cache[i][0] = min(cache[i-1][0] + rock[0][i-1], cache[i-2][0] + rock[1][i-2]);
        cache[i][1] = min(min(cache[i-1][1] + rock[0][i-1], cache[i-2][1] + rock[1][i-2]), k + cache[i-3][0]);

    cout << min(cache[n][0], cache[n][1]);
    
}
