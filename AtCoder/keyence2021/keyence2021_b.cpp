#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    v.resize(N+1);
    for(int i=0;i<N;i++) {
        int a;
        cin>>a;
        v[a]++;
    }
    ll box = K;
    ans = 0;
    for(int i=0;i<N;i++) {
        box = min(box,v[i]);
        ans+=box;
    }
    cout<<ans<<"\n";
    return 0;
}