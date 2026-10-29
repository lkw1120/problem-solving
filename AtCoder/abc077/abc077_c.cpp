#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v[3];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<3;i++) {
        v[i].resize(N);
        for(int j=0;j<N;j++) {
            cin>>v[i][j];
        }
        sort(v[i].begin(),v[i].end());
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        auto a = lower_bound(v[0].begin(),v[0].end(),v[1][i])-v[0].begin();
        auto c = upper_bound(v[2].begin(),v[2].end(),v[1][i])-v[2].begin();
        ans+=a*(N-c);
    }
    cout<<ans<<"\n";
    return 0;
}