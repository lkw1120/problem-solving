#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    ll weight = 0;
    for(int i=0;i<=K;i++) {
        ll cnt;
        cin>>cnt;
        ll cur = 1LL<<i;
        if(weight+1 < cur) {
            break;
        }
        weight+=cur*cnt;
    }
    ans = weight+1;
    cout<<ans<<"\n";
    return 0;
}