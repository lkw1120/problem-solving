#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,K,V,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>K>>V;
        ans = 0;
        for(ll i=-V;i<=V;i++) {
            for(ll j=-V;j<=V;j++) {
                if(abs(i+j) <= V) {
                    ll low = max(0LL,max(-i,-i-j));
                    ll high = min(K,min(K-i,K-i-j));
                    ans+=high-low+1;
                }
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}