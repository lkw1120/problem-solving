#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+1;
ll a,b,c,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    ans = LLONG_MAX;
    for(ll A=1;A<MAX;A++) {
        ll tmp = c/A;
        for(ll B=tmp;B<=tmp+1;B++) {
            if(B < 1) continue;
            ll C = A*B;
            ll sum = llabs(A-a)+llabs(B-b)+llabs(C-c);
            ans = min(ans,sum);
        }
    }
    cout<<ans<<"\n";
    return 0;
}