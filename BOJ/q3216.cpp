#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,D,V,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>D>>V;
        v.push_back({D,V});
    }
    int t = 0;
    ans = 0;
    for(int i=0;i<N;i++) {
        D = v[i].first;
        V = v[i].second;
        t-=V;
        if(t < 0) {
            ans-=t;
            t = 0;
        }
        t+=D;
    }
    cout<<ans<<"\n";
    return 0;
}