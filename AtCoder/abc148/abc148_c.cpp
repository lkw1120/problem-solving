#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    ans = A*B/gcd(A,B);
    cout<<ans<<"\n";
    return 0;
}