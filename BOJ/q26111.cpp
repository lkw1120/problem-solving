#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<char> st;
string str;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int size = str.size();
    ans = 0;
    for(int i=0;i<size;i++) {
        if(str[i] == '(') {
            st.push('(');
        }
        else {
            st.pop();
            if(str[i-1] == '(') {
                ans+=st.size();
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}