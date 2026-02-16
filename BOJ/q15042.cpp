#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll n = N;
    ll k = 0;
    if(n%2 == 0) {
        k++;
        while(n%2 == 0) n/=2;
    }
    for(ll p=3;p*p<=n;p+=2) {
        if(n%p == 0) {
            k++;
            while(n%p == 0) n/=p;
        }
    }
    if(1 < n) k++;
    ans = k < 2? 0LL: (1LL<<k)-1-k;
    cout<<ans<<"\n";
    return 0;
}