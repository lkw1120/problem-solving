#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll T,N,ans;
ll modpow(ll a, ll n, ll p) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = res*a%p;
        }
        a = a*a%p;
        n>>=1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        ans = 1;
        if(3 <= N) {
            ans = modpow(2,N-2,MOD);
        }
        cout<<ans<<"\n";
    }
    return 0;
}