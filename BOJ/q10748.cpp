#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int arr[101][101] = {0};
int dp[101][101] = {0};
int R,C,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>K;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			cin>>arr[i][j];
		}
	}
	dp[1][1] = 1;
	for(int i=1;i<R;i++) {
		for(int j=1;j<C;j++) {
			if((i == 1 && j == 1) || dp[i][j]) {
				for(int k=i+1;k<=R;k++) {
					for(int l=j+1;l<=C;l++) {
						if(arr[k][l] != arr[i][j]) {
							dp[k][l] = (dp[k][l]+dp[i][j])%MOD;
						}
					}
				}
			}
		}
	}
	ans = dp[R][C];
	cout<<ans<<"\n";
	return 0;
}