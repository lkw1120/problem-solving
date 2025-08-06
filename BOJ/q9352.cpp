#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[101];
ll cost[101];
ll dp[10001];
ll T,N,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>X;
        fill(arr,arr+101,0);
        fill(cost,cost+101,0);
        for(int i=0;i<N;i++) {
            cin>>arr[i];
        }
        for(int i=0;i<N;i++) {
            cin>>cost[i];
        }
        fill(dp,dp+10001,0);
        for(int i=0;i<N;i++) {
            ll a = cost[i];
            ll tmp = arr[i];
            for(int j=a;j<=X;j++) {
                dp[j] = max(dp[j],dp[j-a]+tmp);
            }
        }
        ans = dp[X];
        cout<<ans<<"\n";
    }
    return 0;
}