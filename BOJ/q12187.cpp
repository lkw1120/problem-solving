#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
set<string> st;
string s1,s2;
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        mp.clear();
        st.clear();
        cin>>N;
        for(int i=0;i<N;i++) {
            cin>>s1>>s2;
            mp[s1] = s2;
            st.insert(s2);
        }
        string str;
        for(auto [a,b]: mp) {
            if(st.count(a) == 0) {
                str = a;
                break;
            }
        }
        cout<<"Case #"<<t<<": ";
        while(mp.count(str)) {
            cout<<str<<"-"<<mp[str]<<" "; 
            str = mp[str];
        }
        cout<<"\n";
    }
    return 0;
}