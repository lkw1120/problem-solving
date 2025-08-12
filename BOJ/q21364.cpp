#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LONG_LONG_MAX;
const int MAX_N = 2010;
ll arr[MAX_N];
ll dp[2][MAX_N];
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        dp[0][i] = dp[1][i] = arr[i];
    }
    for(int k=2;k<=K;k++) {
        ll tmp = INF;
        for(int i=1;i<=N;i++) {
            dp[1][i] = (tmp < INF)? (arr[i]+i+tmp): INF;
            if(dp[0][i] < INF) {
                tmp = min(tmp,dp[0][i]-i);
            }
        }
        for(int i=1;i<=N;i++) {
            dp[0][i] = dp[1][i];
        }
    }
    ans = INF;
    for(int i=1;i<=N;i++) {
        ans = min(ans, dp[0][i]);
    }
    cout<<ans<<"\n";
    return 0;
}