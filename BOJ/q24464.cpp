#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[5] = {0};
ll arr[5] = {0};
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    fill(dp,dp+5,1);
    for(int i=2;i<=N;i++) {
        arr[0] = (dp[1]+dp[2]+dp[3]+dp[4])%MOD;
        arr[1] = (dp[0]+dp[3]+dp[4])%MOD;
        arr[2] = (dp[0]+dp[4])%MOD;
        arr[3] = (dp[0]+dp[1])%MOD;
        arr[4] = (dp[0]+dp[1]+dp[2])%MOD;
        for(int j=0;j<5;j++) {
            dp[j] = arr[j];
        }
    }
    ans = 0;
    for(int i=0;i<5;i++) {
        ans=(ans+dp[i])%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}