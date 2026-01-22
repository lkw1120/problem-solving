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
    ll g = gcd(A,B);
    ll a = A/g;
    ll b = B/g;
    if(a == 1 || b == 1) {
        ans = max(A,B)-g;
    }
    else {
        ll l = (A/g)*B;
        ans = l-A-B;
    }
    cout<<ans<<"\n";
    return 0;
}