#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pair;
vector<Pair> v;
ll N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
    }
    sort(v.begin(),v.end());
    X = v[N/2].first;
    sort(v.begin(),v.end(),[](Pair a, Pair b) {
        return a.second < b.second;
    });
    Y = v[N/2].second;
    ans = 0;
    for(auto item: v) {
        ans+=abs(X-item.first)+abs(Y-item.second);
    }
    cout<<ans<<"\n";
    return 0;
}