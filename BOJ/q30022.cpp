#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,A,B,P,Q,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>A>>B;
    ans = 0;
    for(int i=1;i<=N;i++) {
        cin>>P>>Q;
        ans+=P;
        v.push_back(Q-P);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<B;i++) {
        ans+=v[i];
    }
    cout<<ans<<"\n";
    return 0;
}