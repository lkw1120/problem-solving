#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 12345678910LL;
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
    vector<ll> pow2(N+1,1);
    for(int i=1;i<=N;i++) {
        pow2[i] = (pow2[i-1]*2LL)%MOD;
    }
    ans = 0;
    int depth = 0;
    for(int i=0;i<N;i++) {
        if(v[i] == 0) {
            depth++;
        }
        else {
            if(i > 0 && v[i-1] == 0) {
                ans = (ans+pow2[depth-1])%MOD;
            }
            depth--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}