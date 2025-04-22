#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
ll N,A,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll cnt = 0;
    for(int i=0;i<N;i++) {
        cin>>A>>T;
        v.push_back({A,T});
        cnt = max(A,cnt);
    }
    v.push_back({0,0});
    sort(v.begin(),v.end());
    if(v[N].first < v[N].second) {
        cnt+=(v[N].second-v[N].first);
    }
    for(int i=N-1;i>=0;i--) {
        auto [a,t] = v[i];
        if(cnt < t) {
            cnt+=(t-cnt);
        }
        else {
            cnt+=v[i+1].first-a;
        }
    }
    ans = cnt;
    cout<<ans<<"\n";
    return 0;
}