#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L,R,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>L>>R>>A;
    ll N = R-L+1;
    ll Q = N/A;
    ll rest = N%A;
    ll a = (Q-1)*Q/2;
    ll b = Q*(Q+1)/2;
    ans = rest*b+(A-rest)*a;
    cout<<ans<<"\n";
    return 0;
}