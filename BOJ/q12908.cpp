#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pair;
const ll INF = 1LL<<62;
ll ans;
ll manhattan(Pair a, Pair b) {
    return llabs(a.first-b.first)+llabs(a.second-b.second);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Pair start,end;
    cin>>start.first>>start.second;
    cin>>end.first>>end.second;
    vector<Pair> v;
    v.push_back(start);
    v.push_back(end);
    vector<Pair> tp;
    for(int i=0;i<3;i++) {
        Pair a,b;
        cin>>a.first>>a.second>>b.first>>b.second;
        int ia = v.size();
        v.push_back(a);
        int ib = v.size();
        v.push_back(b);
        tp.push_back({ia,ib});
    }
    ll dist[8][8];
    fill(&dist[0][0],&dist[0][0]+8*8,INF);
    for(int i=0;i<8;i++) {
        dist[i][i] = 0;
        for(int j=i+1;j<8;j++) {
            ll warp = manhattan(v[i],v[j]);
            for(auto [a,b]: tp) {
                if((i == a && j == b) || (i == b && j == a)) {
                    warp = min(warp,10LL);
                }
            }
            dist[i][j] = dist[j][i] = warp;
        }
    }
    for(int j=0;j<8;j++) {
        for(int i=0;i<8;i++) {
            for(int k=0;k<8;k++) {
                if(dist[i][j] == INF || dist[j][k] == INF) continue;
                dist[i][k] = min(dist[i][k],dist[i][j]+dist[j][k]);
            }
        }
    }
    ans = dist[0][1];
    cout<<ans<<"\n";
    return 0;
}