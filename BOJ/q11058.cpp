#include<bits/stdc++.h>
#define MAX 101
typedef long long ll;
using namespace std;
ll dp[MAX] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		if(i <= 6) {
			dp[i] = i;
		}
		else {
			for(int j=3;j<i;j++) {
				dp[i] = max(dp[i],dp[i-j]*(j-1));
				if(dp[i] > dp[i-j]*(j-1)) break;
			}
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;
}