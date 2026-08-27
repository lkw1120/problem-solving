#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ll mx = v[0];
    ans = 0;
    for(int i=1;i<N;i++) {
        if(v[i] < mx) {
            ans+=(mx-v[i]);
        }
        else {
            mx = v[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}