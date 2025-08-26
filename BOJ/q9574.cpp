#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll N,X,Y,Z,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>X>>Y>>Z;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        mp[A]+=(Y-X);
        mp[B+1]+=(Z-Y);
    }
    ll tmp = 1LL*N*X;
    ans = tmp;
    for(auto [a,b]: mp) {
        tmp+=b;
        ans = max(ans,tmp);
    }
    cout<<ans<<"\n";
    return 0;
}