#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ll cnt = 0;
    for(int i=N-1;i>=0;) {
        ll d = v[i];
        ll m = 0;
        while(i >= 0 && v[i] == d) { 
            i--;
            m++;
        }
        ll tmp = d-cnt;
        if(0 < tmp) ans+=tmp*m;
        cnt+=m;
    }
    cout<<ans<<"\n";
    return 0;
}