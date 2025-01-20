#include<bits/stdc++.h>
using namespace std;
int T,A,B,C,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>A>>B>>C>>P;
        int cnt = 0;
        if(A%P == 0) cnt++;
        if(B%P == 0) cnt++;
        if(C%P == 0) cnt++;
        ans = 2 <= cnt? 1: 0;
        cout<<ans<<"\n";
    }
    return 0;
}