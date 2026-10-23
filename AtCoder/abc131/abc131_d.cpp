#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
ll N,A,B;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A>>B;
        v.push_back({B,A});
    }
    sort(v.begin(),v.end());
    ll t = 0;
    ans = "Yes";
    for(int i=0;i<N;i++) {
        if(t+v[i].second <= v[i].first) {
            t+=v[i].second;
        }
        else {
            ans = "No";
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}