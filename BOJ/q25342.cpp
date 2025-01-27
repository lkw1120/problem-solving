#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,ans;
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
    cin>>T;
    while(T--) {
        cin>>N;
        ll a,b,c;
        a = lcm(N,lcm(N-1,N-2));
        b = lcm(N,lcm(N-1,N-3));
        c = lcm(N-1,lcm(N-2,N-3));
        ans = max(a,max(b,c));
        cout<<ans<<"\n";
    }
    return 0;
}