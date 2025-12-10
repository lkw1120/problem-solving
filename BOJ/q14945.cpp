#include<bits/stdc++.h>
using namespace std;
const int MOD = 10007;
int dp[205][205];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dp[0][0] = 1;
    int n = 2*N-2;
    int k = N-1;
    for(int i=1;i<=n;i++) {
        dp[i][0] = 1;
        for(int j=1;j<=min(i,k);j++) {
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
        }
    }
    ans = dp[n][k];
    cout<<ans<<"\n";
    return 0;
}