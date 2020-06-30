#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int matrix[MAX][3] = {0};
int dp[3][2] = {0};
int N,ans[2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<3;j++) {
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<3;i++) {
        dp[i][1] = matrix[1][i];
    }
    for(int i=2;i<=N;i++) {
        for(int j=0;j<3;j++) {
            dp[j][0] = dp[j][1];
        }
        dp[0][1] = max(dp[0][0],dp[1][0]) + matrix[i][0];
        dp[1][1] = max(dp[0][0],max(dp[1][0],dp[2][0])) + matrix[i][1];
        dp[2][1] = max(dp[1][0],dp[2][0]) + matrix[i][2];
    }
    ans[0] = max(dp[0][1],max(dp[1][1],dp[2][1]));
    for(int i=0;i<3;i++) {
        dp[i][1] = matrix[1][i];
    }
    for(int i=2;i<=N;i++) {
        for(int j=0;j<3;j++) {
            dp[j][0] = dp[j][1];
        }
        dp[0][1] = min(dp[0][0],dp[1][0]) + matrix[i][0];
        dp[1][1] = min(dp[0][0],min(dp[1][0],dp[2][0])) + matrix[i][1];
        dp[2][1] = min(dp[1][0],dp[2][0]) + matrix[i][2];   
    }
    ans[1] = min(dp[0][1],min(dp[1][1],dp[2][1]));
    cout<<ans[0]<<" "<<ans[1]<<"\n";
    return 0;
}