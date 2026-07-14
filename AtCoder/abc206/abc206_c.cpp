#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(ll i=0;i<N;i++) {
        cin>>A;
        ans+=(i-mp[A]);
        mp[A]++;
    }
    cout<<ans<<"\n";
    return 0;
}