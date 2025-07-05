#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K>>R;
    ll r2 = R*R;
    ll tmp = 0;
    ll limit = R/K+1;
    for(int i=0;i<limit;i++) {
        ll x1 = i*K;
        ll x2 = x1+K;
        double y1 = sqrt(max(0.0,r2-pow(x1,2)));
        double y2 = sqrt(max(0.0,r2-pow(x2,2)));
        ll low = floor(y2/K);
        ll high = ceil(y1/K)-1;
        if(low <= high) {
            tmp+=(high-low+1);
        }
    }
    ans = tmp*4;
    cout<<ans<<"\n";
    return 0;
}