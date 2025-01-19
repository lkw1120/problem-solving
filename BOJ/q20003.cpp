#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,A,B;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>A>>B;
    ll tmp = gcd(A,B);
    A/=tmp;
    B/=tmp;
    while(--N) {
        ll a,b;
        cin>>a>>b;
        tmp = gcd(a,b);
        a/=tmp;
        b/=tmp;
        A = gcd(a,A);
        B = lcm(b,B);
    }
    cout<<A<<" "<<B<<"\n";
    return 0;
}