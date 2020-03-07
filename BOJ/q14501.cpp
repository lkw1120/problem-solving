#include<bits/stdc++.h>
#define MAX 16
using namespace std;
int dp[MAX] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    int N, T, P, ans;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>T>>P;
        dp[i+1] = max(dp[i+1],dp[i]);
        if(i+T<=N) {
            dp[i+T] = max(dp[i+T],dp[i]+P);
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}