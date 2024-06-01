#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,S,E,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>S>>E;
        v.push_back({E,S});
    }
    sort(v.begin(),v.end());
    int p,cnt;
    p = v[0].first;
    cnt = 1;
    for(int i=1;i<N;i++) {
        if(p <= v[i].second) {
            p = v[i].first;
            cnt++;
        }
    }
    ans = cnt;
    cout<<ans<<"\n";
    return 0;
}