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
    ll total = N*(N+1)/2;
    ll zero = 0;
    ll one = 0;
    ll cnt = 1;
    for(int i=1;i<N;i++) {
        if(v[i] == v[i-1]) {
            cnt++;
        }
        else {
            ll add = cnt*(cnt+1)/2;
            if(v[i-1] == 0) {
                zero+=add;
            }
            else {
                one+=add;
            }
            cnt = 1;
        }
    }
    ll add = cnt*(cnt+1)/2;
    if(v[N-1] == 0) {
        zero+=add;
    }
    else {
        one+=add;
    }
    ans = 2*total-2*one-zero;
    cout<<ans<<"\n";
    return 0;
}