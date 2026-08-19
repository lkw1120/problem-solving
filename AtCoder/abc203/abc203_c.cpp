#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
ll N,K,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        v.push_back({A,B});
    }
    sort(v.begin(),v.end());
    ans = K;
    for(auto& [a,b]: v) {
        if(a <= ans) {
            ans+=b;
        }
        else {
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}