#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    ll N = K;
    int n = 0;
    for(ll i=2;i*i<=N;i++) {
        while(N%i == 0) {
            n++;
            N/=i;
        }
    }
    if(1 < N) n++;
    int tmp = 1;
    while(tmp < n) {
        tmp*=2;
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}