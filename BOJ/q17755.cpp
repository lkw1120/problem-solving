#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
const int MAX = 1458;
ll k,a,b,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>a>>b;
    ans = 0;
    for(int i=1;i<=MAX;i++) {
        i128 n = (i128)k*i;
        if(n < a || n > b) continue;
        ll sum = 0;
        ll m = (ll)n;
        while(m > 0) {
            ll d = m%10;
            sum+=1LL*d*d;
            m/=10;
        }
        if(sum == i) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}