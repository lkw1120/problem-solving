#include<bits/stdc++.h>
using namespace std;
int arr[501][501];
int dp[501][501];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,ans;
int find(int x, int y) {
    if(dp[x][y] != 0) {
        return dp[x][y];
    }
    dp[x][y] = 1;
    for(int i=0;i<4;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[x][y] < arr[dx][dy]) {
            dp[x][y] = max(dp[x][y],find(dx,dy)+1);
        }
    }
    return dp[x][y];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            ans = max(ans,find(i,j));
        }
    }
    cout<<ans<<"\n";
    return 0;
}