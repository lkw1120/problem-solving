#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[101][101][2];
int dp[101][101];
int H,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>H>>W;
    for(int k=0;k<2;k++) {
        for(int i=1;i<=H;i++) {
            for(int j=1;j<=W;j++) {
                cin>>arr[i][j][k];
            }
        }
    }
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            dp[i][j] = INF;
        }
    }
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            if(j != 1) {
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            }
            if(j != W) {
                dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
            }
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            int diff = abs(arr[i][j][0]-arr[i][j][1]);
            dp[i][j]+=diff*diff;
        }
    }
    ans = INF;
    for(int j=1;j<=W;j++) {
        ans = min(ans,dp[H][j]);
    }
    cout<<ans<<"\n";
    return 0;
}