#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>K;
        if(64 <= K || (K < 64 && N < (1LL<<K))) {
            ans = 0;
        }
        else {
            ll a,b;
            a = N>>K;
            b = N>>(K+1);
            ans = a-b;
        }
        cout<<ans<<"\n";
    }
    return 0;
}