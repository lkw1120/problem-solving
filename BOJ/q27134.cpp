#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int sum = N*(N+1)/2;
    if(sum%2) {
        ans = 0;
    }
    else {
        int half = sum/2;
        dp[0] = 1;
        for(int i=1;i<=N;i++) {
            for(int j=half;j>=0;j--) {
                if(dp[j] || j == 0) {
                    dp[j+i]+=dp[j];
                }
            }
        }
        ans = dp[half]/2;
    }
    cout<<ans<<"\n";
    return 0;
}