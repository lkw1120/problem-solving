#include<bits/stdc++.h>
using namespace std;
int world[300][300] = {};
bool island[300][300] = {};
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int N,M;
void melt(int y, int x) {        
    for(int i=0;i<4;i++) {
        if( world[y][x] > 0
        && 0 <= y+dY[i] && y+dY[i] < N
        && 0 <= x+dX[i] && x+dX[i] < M
        && world[y+dY[i]][x+dX[i]] == 0
        && !island[y+dY[i]][x+dX[i]]) {
            world[y][x]--;
        }
    }
}
bool remain() {
    bool remain = false;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(world[i][j]>0) {
                remain = true;
                island[i][j] = true;
            }
            else {
                island[i][j] = false;
            }
        }
    }
    return remain;
}
void dfs(int y, int x) {
    island[y][x] = false;
    for(int i=0;i<4;i++) {
        if(0 <= y+dY[i] && y+dY[i] < N
        && 0 <= x+dX[i] && x+dX[i] < M
        && island[y+dY[i]][x+dX[i]]) {
            dfs(y+dY[i],x+dX[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int ans = 0;
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>world[i][j];
        }
    }
    while(true){
        if(remain()) {
            for(int i=0;i<N;i++) {
                for(int j=0;j<M;j++) {
                    melt(i,j);
                }
            }
            remain();
            ans++;
            int cnt = 0;
            for(int i=0;i<N;i++) {
                for(int j=0;j<M;j++) {
                    if(island[i][j]) {
                        dfs(i,j);
                        cnt++;
                    }
                }
            }
            if(cnt > 1) break;
        }
        else {
            ans = 0;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}