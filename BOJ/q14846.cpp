#include<bits/stdc++.h>
using namespace std;
int arr[301][301];
int dp[301][301][11];
int N,Q,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            for(int k=1;k<=10;k++) {
                dp[i][j][k] = dp[i][j-1][k]+dp[i-1][j][k]-dp[i-1][j-1][k];
                if(k == arr[i][j]) dp[i][j][k]++;
            }
        }
    }
    cin>>Q;
    while(Q--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int tmp[11] = {};
        for(int k=1;k<=10;k++) {
            tmp[k]+=dp[x2][y2][k];
            tmp[k]-=dp[x1-1][y2][k];
            tmp[k]-=dp[x2][y1-1][k];
            tmp[k]+=dp[x1-1][y1-1][k];
        }
        ans = 0;
        for(int k=1;k<=10;k++) {
            if(tmp[k]) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}