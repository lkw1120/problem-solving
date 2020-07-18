#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
string str1,str2,str3;
int dp[MAX][MAX][MAX] = {0};
int ans;
int lcs(int S1, int S2, int S3) {
	for(int i=0;i<S1;i++) {
		for(int j=0;j<S2;j++) {
			for(int k=0;k<S3;k++) {
				if (str1[i] == str2[j] && str2[j] == str3[k]) {
					dp[i+1][j+1][k+1] = dp[i][j][k]+1;
				}
				else {
					
					int m = max(dp[i][j][k+1],dp[i][j+1][k]);
					m = max(max(m,dp[i+1][j][k]),dp[i][j+1][k+1]);
					m = max(max(m,dp[i+1][j][k+1]),dp[i+1][j+1][k]);
					dp[i+1][j+1][k+1] = m;
				}
			}
		}
	}
	return dp[S1][S2][S3];
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>str1>>str2>>str3;
	ans = lcs(str1.size(),str2.size(),str3.size());
	cout<<ans<<"\n";
	return 0;
}