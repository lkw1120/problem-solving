#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll N,ans;
ll modpow(ll a, ll e) {
    ll r = 1;
    a%=MOD;
    while(0 < e) {
        if(e&1) {
            r = (r*a)%MOD;
        }
        a = (a*a)%MOD;
        e>>=1;
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll A = modpow(26,N);
    ll B = modpow(22,N);
    ll inv2 = (MOD+1)/2;
    ans = ((A+B)%MOD)*inv2%MOD;
    cout<<ans<<"\n";
    return 0;
}