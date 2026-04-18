#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>N>>X>>Y;
        ll s = N*(N+1)/2;
        ll d = X+Y;
        cout<<"Case #"<<tc<<": ";
        if((s*X)%d != 0) {
            cout<<"IMPOSSIBLE"<<"\n";
        }
        else {
            cout<<"POSSIBLE"<<"\n";
            ll t = (s*X)/d;
            vector<ll> v;
            for(ll i=N;i>=1;i--) {
                if(i <= t) {
                    v.push_back(i);
                    t-=i;
                }
            }
            int size = v.size();
            cout<<size<<"\n";
            for(auto item: v) {
                cout<<item<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}