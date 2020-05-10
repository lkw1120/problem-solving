#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
map<ll,ll> dp;
ll N,ans;
ll fibo(ll n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (dp[n])  return dp[n];

    ll x,f1,f2;
    if (n%2 == 1) {
        ll x = (n+1)/2;
        ll f1 = fibo(x);
        ll f2 = fibo(x-1);
        dp[n] = (f1*f1+f2*f2)%MOD;
        return dp[n];
    }
    else {
        x = n/2;
        f1 = fibo(x);
        f2 = fibo(x-1);
        dp[n] = (2*f2+f1)*f1%MOD;
        return dp[n];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    ans = fibo(N);
    cout<<ans<<"\n";
    return 0;
}