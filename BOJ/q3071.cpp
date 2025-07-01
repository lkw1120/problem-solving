#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        ans = "";
        if(N == 0) {
            ans = "0";
        }
        while(N != 0) {
            ll n = N%3;
            N/=3;
            if(n == 2) {
                n = -1;
                N++;
            }
            else if(n == -2) {
                n = 1;
                N--;
            }
            if(n == -1) {
                ans+="-";
            }
            else if(n == 0) {
                ans+="0";
            }
            else {
                ans+="1";
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
    return 0;
}