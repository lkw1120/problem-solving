#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    ll tmp = gcd(N,M);
    N/=tmp;
    M/=tmp;
    ans = (N%2 && M%2)? tmp: 0;
    cout<<ans<<"\n";
    return 0;
}