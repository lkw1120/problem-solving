#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int dp[MAX][2] = {0};
int arr[MAX] = {0};
int N,L,R,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	fill(&dp[0][0],&dp[MAX-1][2],INT_MIN);
	L = arr[0];
	R = arr[1];
	dp[0][0] = R-L;
    for(int i=1;i<N;i++) {
        if(dp[i-1][0] < arr[i]-L) {
        	R = arr[i];
            dp[i][0] = R-L;
        }
		else {
            dp[i][0] = dp[i-1][0];
		}
        if(arr[i] < L) {
            L = arr[i];
		}
    }
	L = arr[N-2];
	R = arr[N-1];
	dp[N-1][1] = R-L;
	for(int i=N-2;i>=0;i--) {
		if(dp[i+1][1] < R-arr[i]) {
			L = arr[i];
			dp[i][1] = R-L;
		}
		else {
			dp[i][1] = dp[i+1][1];	
		}
		if(R < arr[i]) {
			R = arr[i];	
		}
	}
	ans = INT_MIN;
	for(int i=1;i<N-2;i++) {
		ans = max(ans,dp[i][0]+dp[i+1][1]);
	}
	cout<<ans<<"\n";
	return 0;	
}