#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,N,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>N;
    ll g = gcd(A,B);
    ll l = (A/g)*B;
    ans = N/A+N/B-N/l;
    cout<<ans<<"\n";
    return 0;
}