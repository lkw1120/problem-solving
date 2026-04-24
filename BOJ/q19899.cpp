#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,m,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    if(k == 0) {
        ans = 0;
    }
    else {
        m = llabs(k);
        ans = LLONG_MAX;
        for(ll a=1;a*a<=m;a++) {
            if(m%a != 0) continue;
            ll b = m/a;
            if(k > 0) {
                if((a+b)%2 == 0) {
                    ll x = (a+b)/2;
                    ans = min(ans,x);
                }
            }
            else {
                if((b-a)%2 == 0) {
                    ll x = (b-a)/2;
                    ans = min(ans,x);
                }
            }
        }
    }
    if(ans == LLONG_MAX) {
        cout<<"none"<<"\n";
    } 
    else {
        cout<<ans<<"\n";
    }
    return 0;
}