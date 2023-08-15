#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX] = {0};
int dp[2][MAX] = {0};
int N,A,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A;
		if(A%2) {
			arr[i]++;
		}
		else {
			arr[i]--;
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		dp[0][i] = max(dp[0][i-1]+arr[i],arr[i]);
		dp[1][i] = max(dp[1][i-1]-arr[i],-arr[i]);
		ans = max(ans,max(dp[0][i],dp[1][i]));
	}
	cout<<ans<<"\n";
	return 0;
}