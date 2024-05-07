#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
ll find(ll m) {
    int cnt = 0;
    for(auto item: v) {
        cnt+=item/m;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ll l,r;
    l = 1,r = 1e9;
    ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll cnt = find(mid);
        if(cnt < 4) {
            r = mid-1;
        }
        else {
            ans = mid*mid;
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}