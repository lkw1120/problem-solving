#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3001;
int arr[MAX_N];
int prefix[MAX_N];
int dp[MAX_N][2];
int N,ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int t=0;t<3;t++) {
        for(int i=0;i<=N;i++){
            prefix[i] = dp[i][0] = dp[i][1] = 0;
        }
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
            prefix[i] = prefix[i-1]+arr[i];
        }
        for(int i=1;i<=N;i++) {
            int mn,mx;
            mn = INT_MAX;
            mx = INT_MIN;
            for(int j=0;j<i;j++) {
                int sum = prefix[i]-prefix[j];
                mn = min(mn, sum+dp[j][1]);
                mx = max(mx, dp[j][0]-sum);
            }
            dp[i][0] = mn;
            dp[i][1] = mx;
        }
        ans = dp[N][0];
        if(ans < 0) {
            cout<<"A"<<"\n";
        }
        else if(0 < ans) {
            cout<<"B"<<"\n";
        }
        else {
            cout<<"D"<<"\n";
        }
    }
    return 0;
}