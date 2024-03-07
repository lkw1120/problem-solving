#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int gcd(int a, int b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    if(!N && !M) {
        ans = 0;
    }
    else {
        ans = gcd(abs(N),abs(M));
        if(ans != 1) {
            ans = 2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}