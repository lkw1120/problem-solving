#include<bits/stdc++.h>
using namespace std;
int T,R,C,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>R>>C>>W;
        int a,b;
        a = R*(C/W);
        b = (C%W == 0)? (W-1): W;
        ans = a+b;
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}