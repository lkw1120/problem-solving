#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[81];
ll K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    fill(dp,dp+81,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=K;i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    if(K <= 2) {
        ans = 1;
    } 
    else if(K == 3) {
        ans = 3;
    }
    else if(K == 4) {
        ans = 4;
    }
    else {
        ans = dp[K]-2;
    }
    cout<<ans<<"\n";
    return 0;
}