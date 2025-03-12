#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+1;
const int MOD = 1e9+7;
ll dp[MAX][2];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[1][0] = 2;
    dp[1][1] = 1;
    for(int i=2;i<=N;i++) {
        dp[i][0] = ((dp[i-1][0]+dp[i-1][1])%MOD*2)%MOD;
        dp[i][1] = dp[i-1][0] % MOD;
    }
    ans = (dp[N][0]+dp[N][1])%MOD;
    cout<<ans<<"\n";
    return 0;
}