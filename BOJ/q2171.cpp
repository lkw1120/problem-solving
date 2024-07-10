#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
set<pair<int,int>> st;
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
        st.insert({X,Y});
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            int x1,x2,y1,y2;
            x1 = v[i].first;
            y1 = v[i].second;
            x2 = v[j].first;
            y2 = v[j].second;
            if(x1 != x2 && y1 != y2 && st.count({x1,y2}) && st.count({x2,y1})) {
                ans++;
            }
        }
    }
    ans/=2;
    cout<<ans<<"\n";
    return 0;
}