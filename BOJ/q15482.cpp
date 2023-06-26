#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int dp[3004][3004] = {0};
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str1;
	cin>>str2;
	int size1 = str1.size();
	int size2 = str2.size();
	for(int i=0;i<size1;i+=3) {
		for(int j=0;j<size2;j+=3) {
			if(str1.substr(i,3) == str2.substr(j,3)) {
				dp[i+3][j+3] = dp[i][j]+1;
			}
			else {
				dp[i+3][j+3] = max(dp[i][j+3],dp[i+3][j]);
			}
		}
	}
	ans = dp[size1][size2];
	cout<<ans<<"\n";
	return 0;
}