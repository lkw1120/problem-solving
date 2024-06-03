#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,F,L,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>F>>L;
        v.push_back({F+L,F});
    }
    sort(v.begin(),v.end());
    int p = v[0].first;
    ans = 1;
    for(int i=1;i<N;i++) {
        if(p <= v[i].second) {
            p = v[i].first;
            ans++;
        }   
    }
    cout<<ans<<"\n";
    return 0;
}