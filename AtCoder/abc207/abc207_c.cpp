#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
ll N,T,L,R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>T>>L>>R;
        ll l = 2*L;
        ll r = 2*R;
        if(T == 2) {
            r--;
        }
        else if(T == 3) {
            l++;
        }
        else if(T == 4) {
            l++,r--;
        }
        v.push_back({l,r});
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        auto [a,b] = v[i];
        for(int j=i+1;j<N;j++) {
            auto [c,d] = v[j];
            if(max(a,c) <= min(b,d)) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}