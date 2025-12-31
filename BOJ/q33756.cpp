#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,M;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        if(N%8 != 0) {
            ans = "No";
        }
        else {
            M = N/8;
            int tmp = 9;
            bool flag = true;
            while(0 < M) {
                int d = M%10;
                M/=10;
                if(8 < d || tmp < d) {
                    flag = false;
                    break;
                }
                tmp = d;
            }
            ans = flag? "Yes": "No";
        }
        cout<<ans<<"\n";
    }
    return 0;
}