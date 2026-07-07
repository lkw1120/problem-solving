#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X,K,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X>>K>>D;
    X = abs(X);
    ll cnt = X/D;
    if(K <= cnt) {
        ans = X-K*D;
    }
    else {
        X%=D;
        K-=cnt;
        ans = K%2 == 0? X: abs(X-D);
    }
    cout<<ans<<"\n";
    return 0;
}