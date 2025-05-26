#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll T,C,D,V,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>C>>D>>V;
        v.clear();
        v.resize(D);
        for(int i=0;i<D;i++) {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll tmp,d;
        tmp = d = 0;
        ans = 0;
        while(tmp < V) {
            if(d < D && v[d] <= tmp+1) {
                tmp+=C*v[d];
                d++;
            }
            else {
                ll x = tmp+1;
                tmp+=C*x;
                ans++;
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}