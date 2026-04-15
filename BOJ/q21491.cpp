#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C>>D;
    ans = 0;
    for(ll i=1;i*i<=B;i++) {
        ll low,high;
        low = max(i,(A+i-1)/i);
        high = B/i;
        low = max(low,(C-2*i+1)/2);
        high = min(high,(D-2*i)/2);
        if(low <= high) {
            ans+=(high-low+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}