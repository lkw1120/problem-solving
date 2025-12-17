#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    ll a = sqrtl(A);
    ll b = sqrtl(B);
    if(a < b) {
        ll x = b-a;
        ll y = B-A;
        ll g = gcd(x,y);
        x/=g;
        y/=g;
        cout<<x<<"/"<<y<<"\n";
    }
    else {
        cout<<0<<"\n";
    }
    return 0;
}