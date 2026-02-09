#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7LL;
ll A,B,N,ans;
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
    cin>>A>>B>>N;
    ll M = (1LL<<31)%MOD;
    ans = modpow(M,N-1,MOD);
    cout<<ans<<"\n";
    return 0;
}