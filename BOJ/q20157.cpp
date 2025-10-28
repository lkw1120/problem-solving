#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<ll,ll>,ll> mp;
ll N,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(int i=0;i<N;i++) {
        ll x,y;
        cin>>x>>y;
        ll g = gcd(abs(x),abs(y));
        x/=g;
        y/=g;
        pair<ll,ll> p = {x,y};
        mp[p]++;
        ans = max(ans,mp[p]);
    }
    cout<<ans<<"\n";
    return 0;
}