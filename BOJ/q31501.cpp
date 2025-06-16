#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 3001;
int arr[MAX_N];
int dp[MAX_N][2];
int N,Q,A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        dp[i][0] = dp[i][1] = 1;
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<i;j++) {
            if(arr[j] < arr[i]) {
                dp[i][0] = max(dp[i][0],dp[j][0]+1);
            }
        }
    }
    for(int i=N;i>0;i--) {
        for(int j=N;j>i;j--) {
            if(arr[i] < arr[j]) {
                dp[i][1] = max(dp[i][1],dp[j][1]+1);
            }
        }
    }
    while(Q--) {
        cin>>A;
        ans = dp[A][0]+dp[A][1]-1;
        cout<<ans<<"\n";
    }
    return 0;
}