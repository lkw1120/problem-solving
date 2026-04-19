#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>p>>q;
    ll g = gcd(p, q);
    ll d = q/g;
    ans = 1;
    for(ll i=2;i*i<=d;i++) {
        if(d%i == 0) {
            ans*=i;
            while(d%i == 0) {
                d/=i;
            }
        }
    }
    ans*=d;
    cout<<ans<<"\n";
    return 0;
}