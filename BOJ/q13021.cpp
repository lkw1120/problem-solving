#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>> v;
int N,M;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int L,R;
        cin>>L>>R;
        v.push_back({L,R});
    }
    vector<bool> covered(N+1,false);
    int cnt = 0;
    for(int k = M-1;k>=0;k--) {
        auto [L,R] = v[k];
        bool visible = false;
        for(int i=L;i<=R;i++) {
            if(!covered[i]) {
                visible = true;
                break;
            }
        }
        if(visible) cnt++;
        for(int i=L;i<=R;i++) {
            covered[i] = true;
        }
    }
    ans = 1LL<<cnt;
    cout<<ans<<"\n";
    return 0;
}