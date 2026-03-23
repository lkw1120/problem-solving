#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w,h,n,ans;
bool func(ll x) {
    return (x/w)*(x/h) >= n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>h>>n;
    ll l,r;
    l = 0;
    r = 1;
    while(!func(r)) {
        r*=2;
    }
    while(l+1 < r) {
        ll mid = l+(r-l)/2;
        if(func(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    ans = r;
    cout<<ans<<"\n";
    return 0;
}