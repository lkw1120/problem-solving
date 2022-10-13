#include<bits/stdc++.h>
using namespace std;
int T,N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;
		int* coins = new int[N];
		for(int i=0;i<N;i++) {
			cin>>coins[i];
		}
		cin>>M;
		int* dp = new int[M+1];
		fill(dp,dp+M+1,0);
		for(int i=0;i<N;i++) {
			dp[coins[i]]++;
			for(int j=coins[i]+1;j<=M;j++) {
				dp[j]+=dp[j-coins[i]];
			}
		}
		cout<<dp[M]<<"\n";
	}
	return 0;	
}