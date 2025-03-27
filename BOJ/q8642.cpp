#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll n = N;
    ll m = 1;
    for(ll i=2;i*i<=N;i++) {
        int cnt = 0;
        while(N%i == 0) {
            cnt++;
            N/=i;
        }
        if(cnt%2 == 1) {
            m*=i;
        }
    }
    if(1 < N) {
        m*=N;
    }
    ans = n*m;
    cout<<ans<<"\n";
    return 0;
}