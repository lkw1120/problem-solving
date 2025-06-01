#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 17;
ll dp[MAX_N][4];
ll N,ans;
void init() {
    for(int j=0;j<4;j++) {
        dp[1][j] = 1;
    }
    for(int i=2;i<MAX_N;i++) {
        for(int j=0;j<4;j++) {
            dp[i][j] = 0;
            for(int k=0;k<4;k++) {
                if(abs(k-j) == 3) continue;
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    while(1) {
        cin>>N;
        if(N < 1) break;
        ans = 0;
        if(3 <= N) {
            ll cnt = 0;
            for(int j=0;j<4;j++) {
                cnt+=dp[N][j];
            }
            ll pow2,pow4;
            pow2 = 1LL<<N;
            pow4 = 1LL<<(2*N);
            ans = pow4-cnt-pow2+2;
        }
        cout<<N<<": "<<ans<<"\n";
    }
    return 0;
}