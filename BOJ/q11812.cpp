#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K,Q,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>Q;
    if(K == 1) {
        while(Q--) {
            ll x,y;
            cin>>x>>y;
            ans = llabs(x-y);
            cout<<ans<<"\n";
        }
    }
    else {
        while(Q--) {
            ll x,y;
            cin>>x>>y;
            ans = 0;
            while(x != y) {
                if(x > y) {
                    x = (x-2)/K+1;
                } 
                else {
                    y = (y-2)/K+1;
                }
                ans++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}