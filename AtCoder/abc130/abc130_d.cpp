#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100001;
ll arr[MAX];
ll dp[MAX];
ll N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		dp[i] = dp[i-1]+arr[i];
	}
	int low,high;
	low = 0;
	high = 1;
	ans = 0;
	while(low < high && high <= N) {
		while(dp[high]-dp[low] < K && high <= N) high++;
		while(K <= dp[high]-dp[low] && low < high) {
			ans+=(N-high+1);
			low++;
		}
		if(low == high) high++;
	}
	cout<<ans<<"\n";
	return 0;
}