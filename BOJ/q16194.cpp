#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int dp[MAX] = {0};
int cards[MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>cards[i];
		dp[i] = cards[i];
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=i;j++) {
			dp[i] = min(dp[i],dp[i-j]+cards[j]);
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;	
}