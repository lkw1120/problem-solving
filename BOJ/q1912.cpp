#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX] = {0};
int dp[MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    dp[0] = arr[0];
    ans = dp[0];
    for(int i=1;i<N;i++) {
        dp[i] = max(arr[i]+dp[i-1],arr[i]);
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
	return 0;
}