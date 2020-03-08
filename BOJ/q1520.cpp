#include<bits/stdc++.h>
#define MAX 500
using namespace std;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int Map[MAX][MAX] = {0};
long dp[MAX][MAX] = {0};
int M,N;
long ans;
long dfs(int x,int y){
    if(x == 0 && y == 0) {
        return 1;
    }
    if(dp[x][y] == -1) {
        dp[x][y] = 0;
        for(int i=0;i<4;i++) {
            if(0 <= x+dX[i] && x+dX[i] < M
            && 0 <= y+dY[i] && y+dY[i] < N
            && Map[x][y] < Map[x+dX[i]][y+dY[i]]) {
                dp[x][y]+=dfs(x+dX[i],y+dY[i]);
            }
        }
    }
    return dp[x][y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>M>>N;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            cin>>Map[i][j];
            dp[i][j] = -1;
        }
    }
    ans = dfs(M-1,N-1);
    cout<<ans<<"\n";
    return 0;
}