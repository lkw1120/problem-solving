#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ans = 0;
    for(int i=1;i<=N-2;i++) {
        ll a = 2*v[i]-v[0]-v[i+1];
        ll b = v[i-1]+v[N-1]-2*v[i];
        ans = max(ans,max(a,b));
    }
    cout<<ans<<"\n";
    return 0;
}