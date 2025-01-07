#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e6;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll a,b,c;
    ans = 0;
    for(int i=2;i<=N/2;i++) {
        a = N/i;
        b = N/a;
        c = (a-1)*(b-i+1)*(i+b)/2;
        ans = (ans+c)%MOD;
        i = b;
    }
    cout<<ans<<"\n";
    return 0;
}