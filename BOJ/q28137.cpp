#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll N,K,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        mp[Y-K*X]++;
    }
    ans = 0;
    for(auto [a,b]: mp) {
        ans+=b*(b-1);
    }
    cout<<ans<<"\n";
    return 0;
}