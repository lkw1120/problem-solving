#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7LL;
vector<ll> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ans = 1;
    for(int i=0;i<N;i++) {
        ll tmp = v[i]-i;
        if(tmp <= 0) {
            ans = 0;
            break;
        }
        ans = (ans*(tmp%MOD))%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}