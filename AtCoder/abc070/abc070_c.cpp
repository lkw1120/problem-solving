#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ans = v[0];
    for(int i=1;i<N;i++) {
        ll GCD = gcd(ans,v[i]);
        ans = (v[i]/GCD)*ans;
    }
    cout<<ans<<"\n";
    return 0;
}