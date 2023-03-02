#include<bits/stdc++.h>
using namespace std;
int arr[100001][3] = {0};
int dp[100001][3][2] = {0};
int N,ans1,ans2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    dp[0][0][0] = dp[0][0][1] = arr[0][0];
    dp[0][1][0] = dp[0][1][1] = arr[0][1];
    dp[0][2][0] = dp[0][2][1] = arr[0][2];
    for(int i=1;i<N;i++) {
        dp[i][0][0] = max(dp[i-1][0][0],dp[i-1][1][0])+arr[i][0];
        dp[i][1][0] = max(max(dp[i-1][0][0],dp[i-1][1][0]),dp[i-1][2][0])+arr[i][1];
        dp[i][2][0] = max(dp[i-1][1][0],dp[i-1][2][0])+arr[i][2];
        dp[i][0][1] = min(dp[i-1][0][1],dp[i-1][1][1])+arr[i][0];
        dp[i][1][1] = min(min(dp[i-1][0][1],dp[i-1][1][1]),dp[i-1][2][1])+arr[i][1];
        dp[i][2][1] = min(dp[i-1][1][1],dp[i-1][2][1])+arr[i][2];
    }
    ans1 = 0;
    ans2 = INT_MAX;
    for(int i=0;i<3;i++) {
        ans1 = max(ans1,dp[N-1][i][0]);
        ans2 = min(ans2,dp[N-1][i][1]);
    }
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}