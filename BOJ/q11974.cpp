#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 5e5+1;
ll arr[MAX] = {0};
ll dp[MAX] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
		dp[i] = dp[i-1]+arr[i];
	}
	for(ll i=0;i<=N;i++) {
		for(ll j=i+1;j<=N;j++) {
			ll sum = dp[j]-dp[i];
			if(sum%7 == 0) {
				ans = max(ans,j-i);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}