#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const INF = 987654321;
ll T,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>C;
        vector<ll> a,p,dp;
        a.resize(C+1);
        p.resize(C+1);
        dp.resize(C+1,INF);
        for(int i=1;i<=C;i++) {
            cin>>a[i]>>p[i];
        }
        dp[0] = 0;
        for(int i=1;i<=C;i++) {
            ll sum = 0;
            for(int j=i;j>0;j--) {
                sum+=a[j];
                dp[i] = min(dp[i],dp[j-1]+(sum+10)*p[i]);
            }
        }
        ans = dp[C];
        cout<<ans<<"\n";
    }
    return 0;
}