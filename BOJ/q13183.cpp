#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll H,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>H>>W;
    ll a = (H+2)%MOD;
    ll b = (W+2)%MOD;
    ans = (a*b)%MOD;
    cout<<ans<<"\n";
    return 0;
}