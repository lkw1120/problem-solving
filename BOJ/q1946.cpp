#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int T,N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--) {
        v.clear();
        cin>>N;
        for(int i=0;i<N;i++) {
            cin>>X>>Y;
            v.push_back({X,Y});
        }
        ans = 1;
        sort(v.begin(),v.end());
        Y = v[0].second;
        for(int i=1;i<N;i++) {
            if(Y > v[i].second) ans++;
            Y = min(Y,v[i].second);
        }
        cout<<ans<<"\n";
    }
    return 0;
}