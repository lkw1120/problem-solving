#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dp[101][101];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(&dp[0][0],&dp[0][0]+101*101,-1);
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    dp[0][0] = 0;
    for(int k=1;k<=M;k++) {
        for(int i=0;i<=N;i++) {
            if(dp[k-1][i] != -1) {
                for(int j=0;j<=N;j++) {
                    if(N < i+j) break;
                    dp[k][i+j] = max(dp[k][i+j],dp[k-1][i]+arr[k][j]);
                }
            }
        }
    }
    ans = 0;
    for(int i=0;i<=N;i++) {
        ans = max(ans,dp[M][i]);
    }
    cout<<ans<<"\n";
    return 0;
}