#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,ans;
ll leap(ll x) {
    return x/4-x/100+x/400;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    ans = leap(B)-leap(A-1);
    cout<<ans<<"\n";
    return 0;
}