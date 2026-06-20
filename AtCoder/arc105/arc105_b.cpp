#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,A,ans;
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>ans;
    for(int i=1;i<N;i++) {
        cin>>A;
        ans = gcd(ans,A);
    }
    cout<<ans<<"\n";
    return 0;
}