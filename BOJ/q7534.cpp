#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
set<string> st;
string s1,s2;
int T,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        mp.clear();
        st.clear();
        cin>>N;
        for(int i=1;i<N;i++) {
            cin>>s1>>s2;
            mp[s1] = s2;
            st.insert(s1);
        }
        for(auto [a,b]:mp) {
            st.erase(b);
        }
        queue<string> q;
        for(auto item:st) {
            q.push(item);
        }
        cout<<"Scenario #"<<t<<":"<<"\n";
        while(!q.empty()) {
            string str = q.front();
            cout<<str<<"\n";
            q.pop();
            if(mp.count(str)) {
                q.push(mp[str]);
            }
        }
        cout<<"\n";
    }
    return 0;
}