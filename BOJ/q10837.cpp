#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,C,M,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K>>C;
    while(C--) {
        cin>>M>>N;
        ll m = max(0LL,2*N-K-1);
        ll n = max(0LL,2*M-K-2);
        ans = (m <= M && n <= N)? 1: 0;
        cout<<ans<<"\n";
    }
    return 0;
}