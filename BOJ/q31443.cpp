#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    if(N < 3 && M < 3) {
        ans = N*M;
    }
    else {
        ll a,b;
        a = N*M/3;
        b = N*M%3;
        ans = 1;
        if(b == 1) a--;
        while(a--) {
            ans*=3;
            ans%=MOD;
        }
        if(b == 1) {
            ans*=4;
        }
        if(b == 2) {
            ans*=2;
        }
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}