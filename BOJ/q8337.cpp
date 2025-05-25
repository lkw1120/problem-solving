#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(ll i=1;i*i<=N;i++) {
        ll tmp = N/i;
        if(tmp < i) break;
        ans+=(tmp-i+1);
    }
    cout<<ans<<"\n";
    return 0;
}