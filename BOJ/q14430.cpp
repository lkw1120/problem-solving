#include<bits/stdc++.h>
using namespace std;
int arr[301][301] = {0};
int dp[301][301] = {0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];
        }
    }
    ans = dp[N][M];
    cout<<ans<<"\n";
    return 0;
}