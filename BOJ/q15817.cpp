#include<bits/stdc++.h>
using namespace std;
int dp[10001] = {0};
int N,X,L,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X;
    dp[0] = 1;
    for(int i=0;i<N;i++) {
        cin>>L>>C;
        for(int j=X;j>=0;j--) {
            if(dp[j] || j == 0) {
                for(int k=1;k<=C;k++) {
                    if(X < j+L*k) break;
                    dp[j+L*k]+=dp[j];
                }
            }
        }
    }
    ans = dp[X];
    cout<<ans<<"\n";
    return 0;
}