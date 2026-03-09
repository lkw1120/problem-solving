#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,D;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    cin>>D;
    ll g = gcd(N,M);
    ll len = min(g,1000000LL);
    for(ll i=0;i<len;i++) {
        cout<<D;
    }
    cout<<"\n";
    return 0;
}