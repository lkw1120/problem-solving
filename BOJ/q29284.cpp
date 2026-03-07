#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v,vv;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N+1);
    vv.resize(N+2);
    for(int i=1;i<=N;i++) {
        cin>>v[i];
    }
    for(int j=1;j<=N;j++) {
        ll l = j+1;
        ll r = j+v[j]-1;
        if(N < l) continue;
        r = min(r,N);
        if(l <= r) {
            vv[l]++;
            vv[r+1]--;
        }
    }
    ll cur = 0;
    ans = 0;
    for(int i=1;i<=N;i++) {
        cur+=vv[i];
        ans+=cur*v[i];
    }
    cout<<ans<<"\n";
    return 0;
}