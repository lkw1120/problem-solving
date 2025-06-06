#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,J,P,Q,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>N>>P>>Q>>J>>K;
        if(!N && !P && !Q && !J && !K) break;
        vector<vector<ll>> dp(K+1,vector<ll>(N,0LL));
        dp[0][J] = 1;
        for(ll i=0;i<K;i++) {
            for(ll j=0;j<N;j++) {
                if(dp[i][j] == 0) continue;
                if(0 < j) {
                    dp[i+1][j-1]+=dp[i][j];
                }
                if(j < N-1) {
                    dp[i+1][j+1]+=dp[i][j];
                }
            }
        }
        ans = 0;
        for(ll j=P;j<=Q;j++) {
            ans+=dp[K][j];
        }
        cout<<ans<<"\n";
    }
    return 0;
}