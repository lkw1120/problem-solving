#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
ll A,B,C,ans;
ll modpow(lll a, lll n, lll p) {
    if(n == 0) return 1;
    lll half = modpow(a,n/2,p);
    half = (half*half)% p;
    if(n%2 == 1) half = (half*a)%p;
    return half;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B>>C;
    ans = modpow(A,B,C);
    cout<<ans<<"\n";
    return 0;
}