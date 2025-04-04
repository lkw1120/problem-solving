#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
ll arr[MAX];
ll dp[MAX];
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        fill(arr,arr+MAX,0);
        fill(dp,dp+MAX,0);
        cin>>N;
        ll sum = 0;
        for(int i=0;i<N;i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        for(int i=1;i<N;i++) {
            dp[i] = dp[i-1]+arr[i-1];
        }
        ans = 1e18;
        for(int i=0;i<N;i++) {
            ll tmp = 0;
            if(i == 0 || i == N-1) {
                tmp = sum-arr[i];
            }
            else {
                ll a = dp[i];
                ll b = sum-dp[i+1];
                tmp = (sum-arr[i])+min(a,b);
            }
            ans = min(ans,tmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}