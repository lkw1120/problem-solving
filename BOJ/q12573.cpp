#include<bits/stdc++.h>
using namespace std;
int T,L,P,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>L>>P>>C;
        int tmp = C;
        ans = 0;
        while(L*tmp < P) {
            tmp*=tmp;
            ans++;
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}