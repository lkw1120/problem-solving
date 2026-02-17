#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int dp[11][11];
int T,S;
int dfs(int x, int y) {
    int &cnt = dp[x][y];
    if(cnt != -1) return cnt;
    cnt = 1;
    for(int i=0;i<4;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 < dx && dx <= S && 0 < dy && dy <= S) {
            if(arr[x][y]+1 == arr[dx][dy]) {
                cnt = 1+dfs(dx,dy);
                break;
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>S;
        for(int i=1;i<=S;i++) {
            for(int j=1;j<=S;j++) {
                cin>>arr[i][j];
            }
        }
        fill(&dp[0][0],&dp[0][0]+11*11,-1);
        int cnt = 0;
        int n = INT_MAX;
        for(int i=1;i<=S;i++) {
            for(int j=1;j<=S;j++) {
                cnt = max(dfs(i,j),cnt);
            }
        }
        for(int i=1;i<=S;i++) {
            for(int j=1;j<=S;j++) {
                if(dp[i][j] == cnt) {
                    n = min(arr[i][j],n);
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<n<<" "<<cnt<<"\n";
    }
    return 0;
}