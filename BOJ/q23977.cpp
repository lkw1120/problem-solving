#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll K,N,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ans = 1;
    for(int i=0;i<N;i++) {
        ans = ans*v[i]/gcd(ans,v[i]);
    }
    ans-=K;
    cout<<ans<<"\n";
    return 0;
}