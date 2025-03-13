#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MAX = 20001;
ll arr[MAX];
ll dp[MAX];
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    fill(dp,dp+MAX,INF);
    dp[1] = 0;
    for(int i=1;i<N;i++) {
        for(int j=1;j<=K;j++) {
            ll k = i+j;
            if(k <= N) {
                ll cost = abs(arr[i]-arr[k])+(ll)j*j;
                dp[k] = min(dp[k],dp[i]+cost);
            }
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}