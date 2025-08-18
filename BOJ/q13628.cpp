#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
unordered_set<ll> st;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    ll C = 0;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        C+=v[i];
    }
    if(C%3 != 0) {
        ans = 0;
    }
    else {
        ll L = C/3;
        ll tmp = 0;
        st.insert(tmp);
        for(int i=0;i<N-1;i++) {
            tmp = (tmp + v[i])%C;
            st.insert(tmp);
        }
        ll cnt = 0;
        for(auto item: st) {
            ll a = (item + L)%C;
            ll b = (item + 2*L)%C;
            if(st.count(a) && st.count(b)) {
                cnt++;
            }
        }
        ans = cnt/3;
    }
    cout<<ans<<"\n";
    return 0;
}