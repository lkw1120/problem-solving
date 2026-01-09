#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll R,C,ans;
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
    cin>>R>>C;
    ll RC = R*C;
    vector<int> A(RC);
    for(int i=0;i<RC;i++) {
        cin>>A[i];
    }
    vector<int> P(R);
    for(int i=0;i<R;i++) {
        cin>>P[i];
    }
    vector<ll> fact(RC+1);
    fact[0] = 1;
    for(int i=1;i<=RC;i++) {
        fact[i] = fact[i-1]*i%MOD;
    }
    ll tmp = modpow(fact[R],MOD-2,MOD);
    ans = fact[RC]*tmp%MOD;
    cout<<ans<<"\n";
    return 0;
}