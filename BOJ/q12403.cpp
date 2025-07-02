#include<bits/stdc++.h>
using namespace std;
int T,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>A>>B;
        ans = 0;
        for(int i=A;i<=B;i++) {
            string str = to_string(i);
            int size = str.size();
            set<int> st;
            for(int j=1;j<size;j++) {
                string tmp = str.substr(size-j)+str.substr(0,size-j);
                if(tmp[0] == '0') continue;
                int k = stoi(tmp);
                if(i < k && k <= B && !st.count(k)) {
                    st.insert(k);
                    ans++;
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}