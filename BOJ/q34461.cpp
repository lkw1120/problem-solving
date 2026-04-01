#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        ll mn = LLONG_MAX;
        ll mx = LLONG_MIN;
        for(int i=0;i<N;i++) {
            ll x,y,z;
            cin>>x>>y;
            z = x+y;
            mn = min(mn,z);
            mx = max(mx,z);
        }
        ans = 2LL*(mx-mn);
        cout<<ans<<"\n";
    }
    return 0;
}