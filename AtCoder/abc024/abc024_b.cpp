#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>T;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    for(int i=0;i<N-1;i++) {
        ans+=min(T,v[i+1]-v[i]);
    }
    ans+=T;
    cout<<ans<<"\n";
    return 0;
}