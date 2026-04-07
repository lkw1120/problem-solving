#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,K,B,M,X,ans;
bool can(ll d) {
    ll w1 = d-d/K;
    ll w2 = d-d/M;
    if(w1 >= (X+A-1)/A) {
        return true;
    }
    return w2 >= (X-A*w1+B-1)/B;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>K>>B>>M>>X;
    ll l = 1;
    ll h = 1e18;
    ans = h;
    while(l <= h) {
        ll mid = l+(h-l)/2;
        if(can(mid)) {
            ans = mid;
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}