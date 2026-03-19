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
    ll tmp = LLONG_MAX;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        tmp = min(tmp,v[i]);
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ans+=v[i]-tmp;
    }
    cout<<ans<<"\n";
    return 0;
}