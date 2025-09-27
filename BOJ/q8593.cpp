#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll sum = 0;
    for(int i=1;i<=N;i++) {
        ll a,b;
        cin>>a>>b;
        sum+=(a-b);
        mp[sum]++;
    }
    if(sum != 0) {
        cout<<"NIE"<<"\n";
    }
    else {
        ll tmp = 0;
        for(auto [a,b]: mp) {
            tmp = max(tmp,b);
        }
        ans = N-tmp;
        cout<<ans<<"\n";
    }
    return 0;
}