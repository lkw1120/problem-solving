#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C,D,ans;
ll gcd(ll a,ll b) {
    return b == 0? a: gcd(b,a%b);
}
ll solve(ll n, ll c, ll d) {
    ll g = gcd(c,d);
    ll l = c*d/g;
    return n-(n/c)-(n/d)+(n/l);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C>>D;
    ans = solve(B,C,D)-solve(A-1,C,D);
    cout<<ans<<"\n";
    return 0;
}