#include<bits/stdc++.h>
using namespace std;
int T,A,B,X,ans;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>A>>B>>X;
        ans = X/gcd(A,B);
        cout<<ans<<"\n";
    }
    return 0;
}