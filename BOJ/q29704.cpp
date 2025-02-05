#include<bits/stdc++.h>
using namespace std;
int arr[2][1001];
int dp[1001];
int N,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>T;
    for(int i=0;i<N;i++) {
        cin>>arr[0][i]>>arr[1][i];
    }
    int sum = 0;
    for(int i=0;i<N;i++) {
        sum+=arr[1][i];
        for(int t=T;t>=arr[0][i];t--) {
            dp[t] = max(dp[t],dp[t-arr[0][i]]+arr[1][i]);
        }
    }
    int tmp = *max_element(dp+1,dp+T+1);
    ans = sum-tmp;
    cout<<ans<<"\n";
    return 0;
}