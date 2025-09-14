#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll a = 1;
    while((a*2) <= N) {
        a*=2;
    }
    ll m = N-a;
    ll t = (a*a-3*a+2)/6;
    ll r = m*(m+1)/2;
    ans = t+r;
    cout<<ans<<"\n";
    return 0;
}
