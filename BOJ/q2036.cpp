#include<bits/stdc++.h>
#define MAX 100001
typedef long long ll;
using namespace std;
ll arr[MAX] = {0};
ll dp[MAX] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	sort(arr,arr+N);
	ans = 0;
	dp[0] = arr[0];
	dp[1] = max(arr[0]+arr[1],arr[0]*arr[1]);
	for(int i=2;i<N;i++) {
		dp[i] = max(dp[i-2]+arr[i-1]*arr[i],dp[i-1]+arr[i]);
	}
	ans = dp[N-1];
	cout<<ans<<"\n";
	return 0;
}