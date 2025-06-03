#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
const int INF = 987654321;
int arr[MAX];
int dp[MAX];
int N,ans;
int count(int n) {
    int cnt = 0;
    for(int j=N-1;j>=0;j--) {
        if(arr[j] <= n) {
            cnt+=n/arr[j];
            n%=arr[j];
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++) {
        cin>>arr[i];
    }
    fill(dp,dp+MAX,INF);
    dp[0] = 0;
    for(int i=1;i<MAX;i++) {
        for(int j=0;j<N;j++) {
            if(i < arr[j]) break;
            dp[i] = min(dp[i],dp[i-arr[j]]+1);
        }
    }
    ans = -1;
    for(int i=1;i<MAX;i++) {
        int cnt = count(i);
        if(cnt != dp[i]) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}