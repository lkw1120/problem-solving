#include<bits/stdc++.h>
using namespace std;
int T,P,Q,A,B,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>P>>Q>>A>>B>>C>>D;
        int coin;
        coin = (Q/C)*D;
        P+=(coin/B)*A;
        coin%=B;
        int x = (P-coin)/(A+B);
        int a,b;
        a = min(coin+(B*x),P-(A*x));
        b = min(coin+(B*(x+1)),P-(A*(x+1)));
        ans = max(a,b);
        cout<<ans<<"\n";
    }
    return 0;
}