#include<bits/stdc++.h>
using namespace std;
int arr[2][16];
int dp[2][16][16];
int N,K,ans;
int find(int x, int y, int k) {
    if(k == 0) return 0;
    if(y == N) return 0;
    if(dp[x][y][k] != -1) {
        return dp[x][y][k];
    }
    int res = arr[x][y]+find(x,y+1,k-1);
    int dx = (x+1)%2;
    if(1 < k) {
        res = max(res,arr[x][y]+arr[dx][y]+find(dx,y+1,k-2));
    }
    dp[x][y][k] = res;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&dp[0][0][0],&dp[1][15][16],-1);
    cin>>N>>K;
    for(int i=0;i<2;i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
        }
    }
    ans = find(1,0,K);
    cout<<ans<<"\n";
    return 0;
}