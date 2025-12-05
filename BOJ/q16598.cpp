#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>P;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ll best = 0;
    ll i,j;
    i = j = 0;
    while(j < N) {
        while(i <= j) {
            ll len = v[j]-v[i]+1;
            ll cnt = j-i+1;
            ll tmp = len-cnt;
            if(tmp <= P) break;
            i++;
        }
        best = max(best,j-i+1);
        j++;
    }
    ans = best+P;
    cout<<ans<<"\n";
    return 0;
}