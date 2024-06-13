#include<bits/stdc++.h>
using namespace std;
int arr[202][2];
int dp[201][201][3];
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N+1;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    dp[1][1][0] = arr[1][1];
    dp[1][1][1] = arr[1][0];
    dp[1][0][2] = arr[1][0]+arr[1][1];
    for(int i=2;i<=N;i++) {
        for(int j=0;j<=K;j++) {
            if(0 < j) {
                dp[i][j][0] = max(dp[i-1][j-1][0],dp[i-1][j-1][2])+arr[i][1];
                dp[i][j][1] = max(dp[i-1][j-1][1],dp[i-1][j-1][2])+arr[i][0];
            }
            if(j < i) {
                dp[i][j][2] = max(max(dp[i-1][j][0],dp[i-1][j][1]),dp[i-1][j][2]);
                dp[i][j][2]+=arr[i][0]+arr[i][1];
            }
        }
    }
    ans = max(max(dp[N][K][0],dp[N][K][1]),dp[N][K][2]);
    cout<<ans<<"\n";
    return 0;
}