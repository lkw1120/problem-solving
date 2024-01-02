#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 998244353;
ll arr[5001];
ll dp[5001];
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	fill(dp,dp+5001,1);
	for(int i=2;i<=N;i++) {
		for(int j=i-1;j>0;j--) {
			if(arr[j] < arr[i]) {
				dp[i]+=dp[j];
				dp[i]%=MOD;
			}
		}	
	}
	for(int i=1;i<=N;i++) {
		cout<<dp[i]<<" ";	
	}
	cout<<"\n";
	return 0;
}