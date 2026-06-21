#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A,B,ans;
ll odd(ll n) {
    return (n+1)/2%2;
}
ll solve(ll n) {
    if(n%2 == 1) {
        return odd(n);
    }
    else {
        return odd(n+1)^(n+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    ans = solve(B)^solve(A-1);
    cout<<ans<<"\n";
    return 0;
}