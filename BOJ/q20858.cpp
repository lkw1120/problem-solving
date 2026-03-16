#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>v[i];
    }
    ll tmp = 0;
    for(int i=N-1;i>=1;i--) {
        tmp = max(v[i+1],2*tmp-v[i+1]);
    }
    ll ans = max(0LL,tmp-v[1]);
    cout<<ans<<"\n";
    return 0;
}