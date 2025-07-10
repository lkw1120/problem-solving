#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,B,T,X,V,N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>C;
    for(int tc=1;tc<=C;tc++) {
        cin>>N>>K>>B>>T;
        vector<ll> x,v;
        for(int i=0;i<N;i++) {
            cin>>X;
            x.push_back(X);
        }
        for(int i=0;i<N;i++) {
            cin>>V;
            v.push_back(V);
        }
        ll cnt1,cnt2;
        ans = cnt1 = cnt2 = 0;
        for(int i=N-1;i>=0 && cnt1<K;i--) {
            ll d = B-x[i];
            ll mx = v[i]*T;
            if(mx >= d) {
                ans+=cnt2;
                cnt1++;
            }
            else {
                cnt2++;
            }
        }
        if(cnt1 >= K) {
            cout<<"Case #"<<tc<<": "<<ans<<"\n";
        }
        else {
            cout<<"Case #"<<tc<<": IMPOSSIBLE"<<"\n";
        }
    }
    return 0;
}