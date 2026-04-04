#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,ans;
ll check(ll p) {
    ll q = p;
    ll res = 0;
    while(true) {
        ll cnt = b/q-(a-1)/q;
        if(cnt > 0) {
            res++;
        }
        else {
            break;
        }
        if(q > b/p) break;
        q*=p;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    ll v2 = check(2);
    ll v5 = check(5);
    ans = min(v2,v5);
    cout<<ans<<"\n";
    return 0;
}