#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<ll>());
    ans = 0;
    for(int i=0;i<N;i++) {
        ans+=(v[i]*(i/K+1));
    }
    cout<<ans<<"\n";
    return 0;
}