#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
ll T,M,K,ans;
bool can(ll n, ll m, ll k) {
    ll q = n/k;
    ll r = n%k;
    i128 cost = (i128)k*q*(q+1)/2+(i128)r*(q+1);
    return cost <= (i128)m;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>M>>K;
        ll l,h;
        l = 0;
        h = M;
        ans = 0;
        while(l <= h) {
            ll mid = l+(h-l)/2;
            if(can(mid,M,K)) {
                ans = mid;
                l = mid+1;
            } 
            else {
                h = mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}