#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
ll N,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll diff = 0;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        v.push_back({2*A+B,A});
        diff+=A;
    }
    sort(v.rbegin(),v.rend());
    ans = 0;
    for(int i=0;i<N;i++) {
        diff-=v[i].first;
        ans++;
        if(diff < 0) break;
    }
    cout<<ans<<"\n";
    return 0;
}