#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll l,r;
    l = 0;
    r = LLONG_MAX;
    ll s = 0;
    for(int i=1;i<=N;i++) {
        ll a;
        cin>>a;
        s = a-s;
        if(i%2 == 0) {
            l = max(l,-s);
        }
        else {
            r = min(r,s);
        }
    }
    ans = 0;
    if(l <= r) {
        ans = r-l+1;
    }
    cout<<ans<<"\n";
    return 0;
}