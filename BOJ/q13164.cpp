#include<bits/stdc++.h>
#define MAX 300001
using namespace std;
int arr[MAX] = {0};
int dp[MAX] = {0};
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	for(int i=1;i<N;i++) {
		dp[i] = arr[i+1]-arr[i];
	}
	sort(dp+1,dp+N);
	ans = 0;
	for(int i=1;i<N-K+1;i++) {
		ans+=dp[i];	
	}
	cout<<ans<<"\n";
	return 0;	
}