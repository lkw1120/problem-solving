#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll T,P,Q,R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>P>>Q>>R;
        ll tmp = min(Q,R);
        ans = (P+tmp-1)%MOD;
        if(ans < 0) {
            ans+=MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}