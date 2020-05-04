#include<bits/stdc++.h>
#define MAX 31
using namespace std;
typedef long long ll;
ll dp[MAX] = {0};
ll N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    ans = 0;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=N;i++) {
        dp[i] = dp[i-1]+dp[i-2]*2;
    }
    if(N%2==1) {
        ans = (dp[N]+dp[(N-1)/2])/2;
    }
    else {
        ans = (dp[N]+dp[N/2]+dp[(N-1)/2]*2)/2;
    }
    cout<<ans<<"\n";
    return 0;
}