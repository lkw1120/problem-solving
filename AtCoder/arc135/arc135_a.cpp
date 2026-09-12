#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
map<ll,ll> dp;
ll X,ans;
ll solve(ll x) {
    if(x <= 4) return x;
    if(dp.count(x)) return dp[x];
    ll a = solve(x/2);
    ll b = solve((x+1)/2);
    return dp[x] = a*b%MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X;
    ans = solve(X);
    cout<<ans<<"\n";
    return 0;
}