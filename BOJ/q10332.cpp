#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,M,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>C>>D;
        v.push_back({C,D});
    }
    sort(v.begin(),v.end());
    ans = N+1;
    if(!v.empty()) {
        int l,r;
        l = INT_MAX;
        r = 0;
        for(auto [a,b]: v) {
            if(r < a) {
                ans+=max(r-l,0)*2;
                l = a;
                r = b;
            }
            else {
                l = min(l,a);
                r = max(r,b);
            }
        }
        ans+=(r-l)*2;
    }
    cout<<ans<<"\n";
    return 0;
}