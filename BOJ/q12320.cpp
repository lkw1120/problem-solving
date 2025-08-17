#include<bits/stdc++.h>
using namespace std;
int T,X,Y,D,S;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>X>>Y;
        D = abs(X)+abs(Y);
        S = 0;
        int cnt = 0;
        while(S < D || ((S-D)%2)) {
            cnt++;
            S+=cnt;
        }
        ans = "";
        for(int i=cnt;i>=1;i--) {
            if(abs(Y) < abs(X)) {
                if(0 < X) { 
                    ans+="E";
                    X-=i;
                }
                else {
                    ans+="W";
                    X+=i;
                }
            }
            else {
                if(0 < Y) {
                    ans+="N";
                    Y-=i;
                }
                else {
                    ans+="S"; 
                    Y+=i;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}