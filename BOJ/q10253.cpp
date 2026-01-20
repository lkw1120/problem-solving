#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        ll a,b;
        cin>>a>>b;
        while(a != 0) {
            ll x = (b+a-1)/a;
            ans = x;
            ll c = a*x-b;
            ll d = b*x;
            if(c == 0) {
                break;
            }
            ll g = gcd(c,d);
            c/=g;
            d/=g;
            a = c;
            b = d;
        }
        cout<<ans<<"\n";
    }
    return 0;
}