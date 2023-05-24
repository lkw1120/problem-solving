#include<bits/stdc++.h>
using namespace std;
int dp[41][41] = {0};
int N,M,R,C,cnt;
string str1,str2,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str1>>str2;
	N = str1.size();
	M = str2.size();
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
            }
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
        }
    }
	cnt = dp[N][M];
	R = N,C = M;
	while(cnt) {
		if(dp[R-1][C] == cnt) {
			R--;	
		}
		else if(dp[R][C-1] == cnt) {
			C--;	
		}
		else {
			ans+=str1[R-1];
			cnt--;
			R--;
			C--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
	return 0;
}