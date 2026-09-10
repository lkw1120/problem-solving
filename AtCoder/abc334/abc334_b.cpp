#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,M,L,R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>M>>L>>R;
    L-=A;
    R-=A;
    ll l = ((L%M)+M)%M;
    ll r = ((R%M)+M)%M;
    ll left = L+(M-l)%M;
    ll right = R-r;
    ans = (left > right)? 0: (right-left)/M+1;
    cout<<ans<<"\n";
    return 0;
}