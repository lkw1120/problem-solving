#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> st;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=2;i*i<=N;i++) {
        ll tmp = i*i;
        while(tmp <= N) {
            st.insert(tmp);
            if(N/i < tmp) break;
            tmp*=i;
        }
    }
    ans = N-st.size();
    cout<<ans<<"\n";
    return 0;
}