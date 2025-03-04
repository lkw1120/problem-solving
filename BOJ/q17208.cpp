#include<bits/stdc++.h>
using namespace std;
int dp[101][301][301];
int X[101],Y[101];
int N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) {
        cin>>X[i]>>Y[i];
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            for(int k=1;k<=K;k++) {
                if(X[i] <= j && Y[i] <= k) {
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-X[i]][k-Y[i]]+1);
                }
                else {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    ans = dp[N][M][K];
    cout<<ans<<"\n";
    return 0;
}