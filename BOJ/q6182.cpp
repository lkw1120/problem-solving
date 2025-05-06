#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    stack<ll> st;
    st.push(N);
    ans = 0;
    while(!st.empty()) {
        ll x = st.top();
        st.pop();
        if(x <= K || (x-K)%2 != 0) {
            ans++;
        }
        else {
            st.push((x+K)/2);
            st.push((x-K)/2);
        }
    }
    cout<<ans<<"\n";
    return 0;
}