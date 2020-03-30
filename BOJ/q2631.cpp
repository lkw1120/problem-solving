#include<bits/stdc++.h>
#define MAX 200
using namespace std;
int kid[MAX] = {0};
int dp[MAX] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>kid[i];
    }
    for(int i=0;i<N;i++) {
        dp[i] = 1;
        for(int j=0;j<i;j++) {
            if(kid[i] > kid[j] && dp[i] < dp[j]+1) {
                dp[i]=dp[j]+1;
            }
        }
    }
    ans = N-*max_element(dp,dp+N);
    cout<<ans<<"\n";
    return 0;
}