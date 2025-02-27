#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[231];
ll T,K,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        fill(dp,dp+231,0);
        cin>>K>>N;
        dp[0] = dp[1] = 1;
        for(int k=2;k<=K;k++) {
            for(int i=210;i>=0;i--) {
                for(int j=1;j<=k;j++) {
                    dp[i+j]+=dp[i];
                }
            }
        }
        ans = dp[N];
        cout<<ans<<"\n";
    }
    return 0;
}