#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
int min_val, max_val;
int coin[701], item[701], res[3];
int cache[100000001];
void dfs(int idx, int cnt){
    if (cnt == 3){
        int result = res[0]+res[1]+res[2];
        
        if (cache[result] == 1) return;
        cache[result] = 1;
        
        for(int i=0;i<M;i++){
            if (item[i] > result) break;
            if (item[i] == result){
                if(max_val < result) max_val = result;
                if(min_val > result) min_val = result;
            }
        }
        return;
    }

    for(int i=idx;i<N;i++){
        res[cnt] = coin[i];
        dfs(i, cnt+1);

    }
}

int main() {

    cin >> T;
    for(int r=0;r<T;r++){
        cin >> N >> M;

        min_val = 100000001;
        max_val = 0;
        memset(coin, 0, sizeof(coin));
        memset(item, 0, sizeof(item));
        memset(cache, 0, sizeof(cache));

        for(int i=0;i<N;i++){
            cin >> coin[i];
        }
        for(int i=0;i<M;i++){
            cin >> item[i];
        }
        sort(coin, coin+N);
        sort(item, item+M);

        dfs(0, 0);
        if (max_val == 0) cout << "#"<<r+1<<" "<< -1 << endl;
        else cout << "#"<<r+1<<" "<<min_val << " " << max_val << endl;
        // for(int i=0;i<M;i++){
        //     cout << item[i] << " ";
        // }
    }
}
