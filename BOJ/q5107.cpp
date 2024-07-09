#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
set<string> st;
string str1,str2;
int N,ans;
void find(string str) {
    queue<string> q;
    q.push(str);
    st.insert(str);
    while(!q.empty()) {
        str = q.front();
        q.pop();
        if(st.count(mp[str])) {
            break;
        }
        else {
            st.insert(mp[str]);
            q.push(mp[str]);
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int t=1;;t++) {
        mp.clear();
        st.clear();
        cin>>N;
        if(!N) break;
        for(int i=0;i<N;i++) {
            cin>>str1>>str2;
            mp[str1] = str2;
        }
        ans = 0;
        for(auto [a,b]: mp) {
            if(!st.count(a)) {
                find(a);
                ans++;
            }
        }
        cout<<t<<" "<<ans<<"\n";
    }
    return 0;
}