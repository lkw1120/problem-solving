#include<bits/stdc++.h>
using namespace std;
int arr[101];
int dp[101][3][2];
int N,K,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=0;i<K;i++) {
        cin>>A>>B;
        arr[A] = B;
    }
    if(arr[1] == 1) {
        dp[1][0][0] = 1;
    }
    else if(arr[1] == 2) {
        dp[1][1][0] = 1;
    }
    else if(arr[1] == 3) {
        dp[1][2][0] = 1;
    }
    else {
        dp[1][0][0] = dp[1][1][0] = dp[1][2][0] = 1;
    }
    for(int i=2;i<=N;i++) {
        if(arr[i] == 1) {
            dp[i][0][0] = (dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][2][0]+dp[i-1][2][1])%10000;
            dp[i][0][1] = dp[i-1][0][0];
        }
        else if(arr[i] == 2) {
            dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][2][0]+dp[i-1][2][1])%10000;
            dp[i][1][1] = dp[i-1][1][0];
        }
        else if(arr[i] == 3) {
            dp[i][2][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][1][0]+dp[i-1][1][1])%10000;
            dp[i][2][1] = dp[i-1][2][0];
        }
        else {
            dp[i][0][0] = (dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][2][0]+dp[i-1][2][1])%10000;
            dp[i][0][1] = dp[i-1][0][0];
            dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][2][0]+dp[i-1][2][1])%10000;
            dp[i][1][1] = dp[i-1][1][0];
            dp[i][2][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][1][0]+dp[i-1][1][1])%10000;
            dp[i][2][1] = dp[i-1][2][0];
        }
    }
    ans = 0;
    for(int j=0;j<3;j++) {
        ans+=dp[N][j][0]+dp[N][j][1];
    }
    ans%=10000;
    cout<<ans<<"\n";
    return 0;
}