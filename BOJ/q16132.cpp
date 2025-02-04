#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1300];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll sum = N*(N+1)/2;
    ans = 0;
    if(sum%2 == 0) {
        sum/=2;
        dp[0] = 1;
        for(int i=1;i<=N;i++) {
            for(int j=sum;j>=i;j--) {
                dp[j]+=dp[j-i];
            }
        }
        ans = dp[sum]/2;
    }
    cout<<ans<<"\n";
    return 0;
}