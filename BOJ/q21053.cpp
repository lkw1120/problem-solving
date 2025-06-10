#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAX_N = 1e6+1;
ll arr[MAX_N];
ll dp[MAX_N];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N; i++) {
        cin>>arr[i];
    }
    ll cnt = 0;
    for(int i=1;i<=N;i++) {
        ll tmp = dp[i-1];
        if(arr[i] == 1) {
            cnt = (cnt+1)%MOD;
            dp[i] = tmp;
        }
        else if(arr[i] == 2) {
            dp[i] = (tmp*2+cnt)%MOD;
        }
        else if(arr[i] == 3) {
            ans = (ans+tmp)%MOD;
            dp[i] = tmp;
        }
    }
    cout<<ans<<"\n";
    return 0;
}