#include<bits/stdc++.h>
using namespace std;
const int MAX_T = 1001;
const int MAX_W = 32;
int prune[MAX_T] = {0};
int dp[MAX_T][MAX_W][2] = {0};
int T,W,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T>>W;
    for(int i=1;i<=T;i++) {
        cin>>prune[i];
    }
    for(int i=1;i<=T;i++) {
        for(int j=1;j<=W+1;j++) {
            if(prune[i] == 1) {
                dp[i][j][0] = max(dp[i-1][j][0]+1, dp[i-1][j-1][1]+1);
                dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]);
            }
            else {
                if(i ==1 && j == 1) continue;
                dp[i][j][0] = max(dp[i-1][j-1][1], dp[i-1][j][0]);
                dp[i][j][1] = max(dp[i-1][j-1][0]+1, dp[i-1][j][1]+1);
            }

        }
    }
    ans = 0;
    for(int i=1;i<=W+1;i++) {
        ans = max(ans,max(dp[T][i][0],dp[T][i][1]));
    }
    cout<<ans<<"\n";
    return 0;
}