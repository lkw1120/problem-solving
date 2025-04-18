#include<bits/stdc++.h>
using namespace std;
uint32_t dp[10001];
int P,M,N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>P;
    while(P--) {
        cin>>K>>M>>N;
        vector<int> v;
        for(int i=1;i<=N;) {
            v.push_back(i);
            if(N/M < i) break;
            i*=M;
        }
        fill(dp,dp+10001,0);
        dp[0] = 1;
        for(int item: v) {
            for(int j=item;j<=N;j++) {
                dp[j]+=dp[j-item];
            }
        }
        cout<<K<<" "<<dp[N]<<"\n";
    }
    return 0;
}