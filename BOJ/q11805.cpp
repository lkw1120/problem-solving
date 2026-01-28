#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,H,L,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>H>>L;
        int d = 0;
        while((1LL<<(d+1)) <= L) d++;
        ll tmp = 1LL<<(d+1);
        ans = L*(H-d)+tmp-1;
        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
    return 0;
}