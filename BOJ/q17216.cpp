#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int dp[MAX] = {0};
int arr[MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		dp[i] = 0;
		for(int j=1;j<i;j++) {
			if(arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j]);
        	}
		}
		dp[i]+=arr[i];
		ans = max(ans,dp[i]);
    }
	cout<<ans<<"\n";
	return 0;
}