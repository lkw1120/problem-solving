#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
string S;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S;
    ll w = 0;
    ll wh = 0;
    ll whe = 0;
    for(char ch: S) {
        if(ch == 'W') {
            w = (w+1)%MOD;
        }
        else if(ch == 'H') {
            wh = (wh+w)%MOD;
        }
        else if(ch == 'E') {
            ll prev = whe;
            ll tmp = ans;
            whe = (whe+wh)%MOD;
            ans = ((2*tmp)%MOD+prev)%MOD;
        }
    }
    ans%=MOD;
    cout<<ans<<"\n";
    return 0;
}