#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int arr[MAX] = {0};
int dp[MAX][2] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    int ans = arr[0];
    for(int i=0;i<N;i++) {
        dp[i][0] = arr[i];
        if(i == 0) continue;
        dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout<<ans<<"\n";
    return 0;
}