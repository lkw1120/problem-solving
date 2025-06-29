#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool arr[31];
ll dp[31];
ll T,N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>M>>K;
        fill(arr,arr+31,false);
        fill(dp,dp+31,0);
        for(int i=1;i<=N;i++) {
            if(M <= i && (i-M)%K == 0) {
                arr[i] = true;
            }
        }
        dp[0] = 1;
        for(int i=1;i<=N;i++) {
            ll cnt = 0;
            for(int j=1;j<=i;j++) {
                if(!arr[j]) {
                    cnt+=dp[i-j];
                }
            }
            dp[i] = cnt;
        }
        ans = dp[N];
        cout<<ans<<"\n";
    }
    return 0;
}