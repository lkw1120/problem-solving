#include<bits/stdc++.h>
using namespace std;
int K,N,ans;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K>>N;
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(i == K) continue;
        if(gcd(i,K) <= 2) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}