#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> st;
int N,M,R,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>R>>C;
        if(st.count({R,C}) || st.count({R+1,C}) || 
        st.count({R,C+1}) || st.count({R+1,C+1})) {
            continue;
        }
        st.insert({R,C});
        st.insert({R+1,C});
        st.insert({R,C+1});
        st.insert({R+1,C+1});
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}