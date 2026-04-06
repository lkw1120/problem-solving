#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,ans;
ll modpow(ll a, ll n, ll p) {
    if(n == 0) return 1;
    ll half = modpow(a,n/2,p);
    half = (half*half)% p;
    if(n%2 == 1) half = (half*a)%p;
    return half;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ans = 0;
    for(int i=1;i<=N;i++) {
        int x;
        cin>>x;
        ans+=modpow(x,i+1,M);
        ans%=M;
    }
    cout<<ans<<"\n";
    return 0;
}