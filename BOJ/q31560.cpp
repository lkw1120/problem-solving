#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    vector<ll> a(N+2,0);
    for(int i=1;i<=N;i++) {
        cin>>a[i];
    }
    vector<ll> d(N+1,0);
    for(int i=1;i<=N-1;i++) {
        d[i] = a[N-i+1]-a[N-i];
    }
    d[N] = a[1];
    ll t = 0;
    ans = 0;
    for(int i=N;i>=1;i--) {
        ll cur = d[i]+t;
        ll x = -cur;
        ans+=llabs(x);
        t+=x;
    }
    cout<<ans<<"\n";
    return 0;
}