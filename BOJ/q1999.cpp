#include<bits/stdc++.h>
using namespace std;
int arr[251][251];
int dp[251][251][2];
int N,B,K,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>B>>K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
            dp[i][j][0] = dp[i][j][1] = arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N-B+1;j++) {
            for(int k=1;k<B;k++) {
                dp[i][j][0] = min(dp[i][j][0],arr[i][j+k]);
                dp[i][j][1] = max(dp[i][j][1],arr[i][j+k]);
            }
        }
    }
    for(int i=1;i<=N-B+1;i++) {
        for(int j=1;j<=N;j++) {
            int low = dp[i][j][0];
            int high = dp[i][j][1];
            for(int k=1;k<B;k++) {
                low = min(low,dp[i+k][j][0]);
                high = max(high,dp[i+k][j][1]);
            }
            arr[i][j] = high-low;
        }
    }
    while(K--) {
        cin>>X>>Y;
        cout<<arr[X][Y]<<"\n"; 
    }
    return 0;
}