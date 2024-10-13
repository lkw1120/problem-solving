#include<bits/stdc++.h>
using namespace std;
double P,Q,R,W,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P>>Q>>R;
    ans = 0;
    if(P == R) {
        W = sqrt(2*P*P);
        H = sqrt(2*(P+Q)*(P+Q));
        ans = W*H;
    }
    if(ans == 0) {
        cout<<0<<"\n";
    }
    else {
        cout.precision(4);
        cout<<fixed;
        cout<<ans<<"\n";
    }
    return 0;
}