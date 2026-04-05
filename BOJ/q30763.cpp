#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans;
ll comb2(ll x) {
    return x*(x-1)/2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    ll m = n/k;
    ll a = k/m;
    ll b = k%m;
    ans = m*((m-b)*comb2(a)+b*comb2(a+1));
    cout<<ans<<"\n";
    return 0;
}