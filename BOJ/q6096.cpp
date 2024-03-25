#include<bits/stdc++.h>
using namespace std;
const int MOD = 5000011;
int dp[100001][2];
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    dp[1][0] = dp[1][1] = 1;
    for(int i=2;i<=N;i++) {
        dp[i][0] = (dp[i-1][0]+dp[i-1][1])%MOD;
        if(i <= K+1) {
            dp[i][1] = dp[i-1][1];
        }
        else {
            dp[i][1] = (dp[i-(K+1)][0]+dp[i-(K+1)][1])%MOD;
        }
    }
    ans = (dp[N][0]+dp[N][1])%MOD;
    cout<<ans<<"\n";
    return 0;
}