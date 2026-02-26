#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>N;
        if(N == 0) break;
        if(N < 3) {
            cout<<"No such base"<<"\n";
            continue;
        }
        if(N == 3) {
            cout<<4<<"\n";
            continue;
        }
        ll M = N-3;
        ll r = (ll)sqrt(M*1.0L);
        ans = LLONG_MAX;
        for(ll i=1;i<=r;i++) {
            if(M%i != 0) continue;
            ll d1 = i;
            ll d2 = M/i;
            if(3 < d1) {
                ans = min(ans,d1);
            }
            if(3 < d2) {
                ans = min(ans,d2);
            }
        }
        if(ans == LLONG_MAX) {
            cout<<"No such base"<<"\n";
        }
        else {
            cout<<ans<<"\n";
        }
    }
    return 0;
}