#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll N,ans;
ll modpow(ll a, ll n, ll p) {
    if(n == 0) return 1;
    ll half = modpow(a,n/2,p);
    half = (half*half)% p;
    if(n%2 == 1) half = (half*a)%p;
    return half;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(int i=0;i<N;i++) {
        ll k;
        cin>>k;
        ans+=modpow(2,k,MOD);
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}