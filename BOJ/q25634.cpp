#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int arr[2][MAX];
int dp[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<2;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(arr[1][i]) {
            ans+=arr[0][i];
            dp[i] = max(dp[i-1]-arr[0][i],-arr[0][i]);
        }
        else {
            dp[i] = max(dp[i-1]+arr[0][i],arr[0][i]);
        }
    }
    int tmp = *max_element(dp+1,dp+N+1);
    ans+=tmp;
    cout<<ans<<"\n";
    return 0;
}