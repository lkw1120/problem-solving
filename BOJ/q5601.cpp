#include<bits/stdc++.h>
using namespace std;
int arr[17][17] = {0};
int dp[17][17] = {0};
int A,B,N,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>X>>Y;
		arr[X][Y] = 1;
	}
	ans = 0;
	if(!arr[1][1] && !arr[A][B]) {
		for(int i=1;i<=A;i++) {
			if(arr[i][1]) break;
			dp[i][1] = 1;
		}
		for(int j=1;j<=B;j++) {
			if(arr[1][j]) break;
			dp[1][j] = 1;
		}
		for(int i=2;i<=A;i++) {
			for(int j=2;j<=B;j++) {
				if(!arr[i][j]) {
					dp[i][j] = dp[i-1][j]+dp[i][j-1];
				}
			}
		}
		ans = dp[A][B];
	}
	cout<<ans<<"\n";
	return 0;
}