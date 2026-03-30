#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        vector<ll> v(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        vector<ll> diff(N-1);
        for(int i=0;i<N-1;i++) {
            diff[i] = v[i+1]-v[i];
        }
        vector<ll> prefix(N-1);
        prefix[0] = diff[0];
        for(int i=1;i<N-1;i++) {
            prefix[i] = min(prefix[i-1],diff[i]);
        }
        ans = LLONG_MAX;
        for(int i=2;i<N-1;i++) {
            ans = min(ans,diff[i]+prefix[i-2]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}