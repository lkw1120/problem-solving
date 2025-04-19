#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool banned[31];
ll dp[31];
int P,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P;
    while(P--) {
        fill(banned,banned+31,false);
        int n,m,k;
        cin>>K>>n>>m>>k;
        for(int i=0;;i++) {
            int x = m+i*k;
            if(n < x) break;
            if(1 <= x) {
                banned[x] = true;
            }
        }
        dp[0] = 1;
        for(int i=1;i<=n;i++) {
            ll cnt = 0;
            for(int j=1;j<=i;j++) {
                if(!banned[j]) {
                    cnt+=dp[i-j];
                }
            }
            dp[i] = cnt;
        }
        cout<<K<<" "<<dp[n]<<"\n";
    }
    return 0;
}