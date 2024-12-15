#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1000001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<1001;i++) {
        arr[i] = i*(2*i-1);
    }
    fill(dp,dp+1000001,INT_MAX);
    dp[1] = 1;
    for(int i=2;i<=N;i++) {
        for(int j=1;j<1001;j++) {
            if(i < arr[j]) {
                break;
            }
            else if(i == arr[j]) {
                dp[i] = min(dp[i],1);
            }
            else {
                dp[i] = min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}