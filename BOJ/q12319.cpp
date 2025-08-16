#include<bits/stdc++.h>
using namespace std;
int T,X,Y;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>X>>Y;
        ans = "";
        for(int i=0;i<abs(X);i++) {
            ans+=(0 < X? "WE": "EW");
        }
        for(int i=0;i<abs(Y);i++) {
            ans+=(0 < Y? "SN": "NS");
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}