#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L,R;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>L>>R;
    ll len = R-L;
    ll x,y;
    for(ll i=len;i>=1;i--) {
        ll a = ((L+i-1)/i)*i;
        if(a+i <= R) {
            x = a;
            y = a+i;
            break;
        }
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}