#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll FACT9 = 362880;
ll T,N,ans;;
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
    cin>>T;
    while(T--) {
        cin>>N;
        ll num = 1;
        for(int i=1;i<=9;i++) {
            num = num*((N+i)%MOD)%MOD;
        }
        ll inv = modpow(FACT9,MOD-2,MOD);
        ans = num*inv%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}