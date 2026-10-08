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
    int cnt = 0;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        if(v[i] <= 0) {
            cnt++;
            v[i]*=(-1);
        }
        ans+=v[i];
    }
    if(cnt%2) {
        sort(v.begin(),v.end());
        ans-=(2*v[0]);
    }
    cout<<ans<<"\n";
    return 0;
}