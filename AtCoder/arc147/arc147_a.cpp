#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<ll> st;
ll N,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A;
        st.insert(A);
    }
    ans = 0;
    while(st.size() > 1) {
        ll mn = *st.begin();
        auto it = prev(st.end());
        ll mx = *it;
        st.erase(it);
        ll r = mx%mn;
        if(r != 0) {
            st.insert(r);
        }
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}