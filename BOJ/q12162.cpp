#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,B,N,ans;
vector<ll> v;
ll func(ll t) {
    if(t < 0) return 0;
    ll sum = 0;
    for(auto item: v) {
        sum+=t/item+1;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>B>>N;
        v.resize(B);
        for(int i=0;i<B;i++) {
            cin>>v[i];
        }
        ans = -1;
        if(N <= B) {
            ans = N;
        }
        else {
            ll l,h;
            l = 0;
            h = 25*N;
            while(l < h) {
                ll mid = (l+h)/2;
                if(func(mid) >= N) {
                    h = mid;
                }
                else {
                    l = mid+1;
                }
            }
            ll t = l;
            ll need = N-func(t-1);
            for(int i=0;i<B;i++) {
                if(t%v[i] == 0) {
                    need--;
                    if(need == 0) {
                        ans = i+1;
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}