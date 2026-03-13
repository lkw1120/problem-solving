#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll even = 1;
    ll odd = 0;
    ll p = 0;
    for(int i=0;i<N;i++) {
        ll x;
        cin>>x;
        p^=(x&1LL);
        if(p == 0) {
            ans+=even;
            even++;
        } 
        else {
            ans+=odd;
            odd++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}